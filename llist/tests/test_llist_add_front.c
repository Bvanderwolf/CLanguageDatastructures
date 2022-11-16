#include "../../munit/munit.h"
#include "../llist.h"
#include "test_llist.h"
#include <stdlib.h>

static char	*size_params[] = {
	"0", "1", "25", "100", "random", NULL
};

static MunitParameterEnum	llist_add_front_params[] = {
	{ "size", size_params },
	{ NULL, NULL }
};

static MunitResult	test_add_front(const MunitParameter params[], void *data)
{
	(void)params;
	(void)data;
	return (MUNIT_OK);
}

static MunitTest	llist_add_front_tests[] = {
	{ "/llist_add_front", test_add_front, NULL, NULL, MUNIT_TEST_OPTION_NONE, llist_add_front_params },
	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

MunitSuite llist_add_front_suite = { "llist", llist_add_front_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE };