#include "../../munit/munit.h"
#include "../llist.h"
#include <stdlib.h>

static char	*params[] = {
	"0", "1", "25", "100", "random", NULL
};

static MunitParameterEnum	llist_last_params[] = {
	{ "size", params },
	{ NULL, NULL }
};

static MunitResult test_size_null()
{
	t_llist	*lst;
	t_llist	*actual;

	lst = NULL;
	actual = llist_last(lst);
	munit_assert_null(actual);
	return (MUNIT_OK);
}

static MunitResult test_custom_size(int size)
{
	t_llist		*lst;
	t_llist		*new;
	t_llist		*expected;
	t_llist		*actual;
	int			count;

	lst = NULL;
	count = 0;
	while (count < size)
	{
		new = llist_new(strdup("content"));
		if (new == NULL)
		{
			llist_clear(&lst, &free);
			return (MUNIT_ERROR);
		}
		llist_add_back(&lst, new);
		count++;
		if (count == size)
			expected = new;
	}
	actual = llist_last(lst);
	munit_assert_ptr_equal(actual, expected);
	llist_clear(&lst, &free);
	return (MUNIT_OK);
}

static MunitResult test_random_size()
{
	int	size;

	size = munit_rand_int_range(1, 1000);
	return (test_custom_size(size));
}

static MunitResult test_last(const MunitParameter params[], void* data)
{
	const char	*param;

	(void)data;
	param = munit_parameters_get(params, "size");
	if (param != NULL)
	{
		if (strcmp(param, "0"))
			return (test_size_null());
		if (strcmp(param, "1"))
			return (test_custom_size(1));
		if (strcmp(param, "25"))
			return (test_custom_size(25));
		if (strcmp(param, "100"))
			return (test_custom_size(100));
		if (strcmp(param, "random"))
			return (test_random_size());
	}
	return (MUNIT_SKIP);
}

static MunitTest	llist_last_tests[] = {
	{ "/llist_last", test_last, NULL, NULL, MUNIT_TEST_OPTION_NONE, llist_last_params },
	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

MunitSuite llist_last_suite = { "llist", llist_last_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE };
