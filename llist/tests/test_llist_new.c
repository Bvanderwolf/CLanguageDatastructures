#include "../../munit/munit.h"
#include "../llist.h"
#include <stdlib.h>
#include <stdio.h>

static char	*params[] = {
	"new", NULL
};

static MunitParameterEnum llist_new_params[] = {
	{ "value", params },
	{ NULL, NULL }
};

static MunitResult test_new(const MunitParameter params[], void *data)
{
	char	c;
	t_llist	*lst;

	(void)params;
	(void)data;
	c = 'c';
	lst = llist_new(&c);
	munit_assert_ptr_not_null(lst);
	if (lst != NULL)
		free(lst);
	return (MUNIT_OK);
}

static MunitTest llist_new_tests[] = {
	{ "/llist_new", test_new, NULL, NULL, MUNIT_TEST_OPTION_NONE, llist_new_params },
	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

MunitSuite llist_new_suite = { "llist", llist_new_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE };
