#include "../../munit/munit.h"
#include "../llist.h"
#include "test_llist.h"
#include <stdlib.h>

static char	*size_params[] = {
	"0", "1", "25", "100", "random", NULL
};

static MunitParameterEnum	llist_add_back_params[] = {
	{ "size", size_params },
	{ NULL, NULL }
};

static MunitResult	test_empty()
{
	t_llist	*lst;
	t_llist	*new;
	
	lst = NULL;
	new = llist_new(strdup("content"));
	if (new == NULL)
		return (MUNIT_ERROR);
	llist_add_back(&lst, new);
	munit_assert_ptr_equal(lst, new);
	llist_clear(&lst, &free);
	return (MUNIT_OK);
}

static MunitResult	test_size(int size)
{
	t_llist	*lst;
	t_llist	*new;
	t_llist	*last;

	lst = generate_test_list(size);
	new = llist_new(strdup("content"));
	if (new == NULL)
		return (MUNIT_ERROR);
	llist_add_back(&lst, new);
	last = llist_last(lst);
	munit_assert_ptr_equal(last, new);
	llist_clear(&lst, &free);
	return (MUNIT_OK);
}

static MunitResult	test_add_back(const MunitParameter params[], void *data)
{
	const char	*param;

	(void)data;
	param = munit_parameters_get(params, "size");
	if (param == NULL)
		return (MUNIT_SKIP);
	if (strcmp(param, "0") == 0)
		return (test_empty());
	if (strcmp(param, "1"))
		return (test_size(1));
	if (strcmp(param, "25"))
		return (test_size(25));
	if (strcmp(param, "100"))
		return (test_size(100));
	if (strcmp(param, "random"))
		return (test_size(munit_rand_int_range(1, 1000)));
	return (MUNIT_OK);
}

static MunitTest	llist_add_back_tests[] = {
	{ "/llist_add_back", test_add_back, NULL, NULL, MUNIT_TEST_OPTION_NONE, llist_add_back_params },
	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

MunitSuite llist_add_back_suite = { "llist", llist_add_back_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE };