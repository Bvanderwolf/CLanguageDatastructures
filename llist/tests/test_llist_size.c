#include "../../munit/munit.h"
#include "../llist.h"
#include <stdlib.h>

static char	*params[] = {
	"0", "1", "25", "100", "random", NULL
};

static MunitParameterEnum llist_size_params[] = {
	{ "size", params },
	{ NULL, NULL }
};

static MunitResult test_size_null()
{
	t_llist		*lst;
	int			actual;
	int			expected;

	lst = NULL;
	actual = llist_size(lst);
	expected = 0;
	munit_assert_int16(actual, ==, expected);
	return (MUNIT_OK);
}

static MunitResult test_custom_size(int size)
{
	t_llist		*lst;
	t_llist		*new;
	int			count;
	int			expected;
	int			actual;

	lst = NULL;
	count = 0;
	expected = size;
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
	}
	actual = llist_size(lst);
	munit_assert_int16(actual, ==, expected);
	llist_clear(&lst, &free);
	return (MUNIT_OK);
}

static MunitResult test_random_size()
{
	int	size;

	size = munit_rand_int_range(1, 1000);
	return (test_custom_size(size));
}

static MunitResult test_size(const MunitParameter params[], void* data)
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

static MunitTest llist_size_tests[] = {
	{ "/llist_size", test_size, NULL, NULL, MUNIT_TEST_OPTION_NONE, llist_size_params },
	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

MunitSuite llist_size_suite = { "llist", llist_size_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE };
