#include "../../munit/munit.h"
#include "../llist.h"
#include <stdlib.h>

static char	*size_params[] = {
	"0", "1", "25", "100", "random", NULL
};

static char	*position_params[] = {
	"-1", "0", "1", "25, ""100", NULL
};

static MunitParameterEnum	llist_find_params[] = {
	{ "size", size_params },
	{ "position", position_params },
	{ NULL, NULL }
};

static MunitResult test_find(const MunitParameter params[], void* data)
{
	(void)params;
	(void)data;
	return (MUNIT_OK);
}

static MunitTest	llist_find_tests[] = {
	{ "/llist_find", test_find, NULL, NULL, MUNIT_TEST_OPTION_NONE, llist_find_params },
	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

MunitSuite llist_find_suite = { "llist", llist_find_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE };
