#include "../../munit/munit.h"
#include "../llist.h"
#include "test_llist.h"
#include <stdlib.h>

static char	*size_params[] = {
	"0", "1", "25", "100", "random", NULL
};

static char	*position_params[] = {
	"-1", "0", "1", "25", "100", NULL
};

static MunitParameterEnum	llist_insert_params[] = {
	{ "size", size_params },
	{ "position", position_params },
	{ NULL, NULL }
};

static int	get_position_value(const char *pos_param)
{
	if (strcmp(pos_param, "-1") == 0)
		return (-1);
	if (strcmp(pos_param, "0") == 0)
		return (0);
	if (strcmp(pos_param, "1") == 0)
		return (1);
	if (strcmp(pos_param, "25") == 0)
		return (25);
	if (strcmp(pos_param, "100") == 0)
		return (100);
	return (INT32_MAX);
}

static int	get_size_value(const char *size_param)
{
	if (strcmp(size_param, "0") == 0)
		return (0);
	if (strcmp(size_param, "1") == 0)
		return (1);
	if (strcmp(size_param, "25") == 0)
		return (25);
	if (strcmp(size_param, "100") == 0)
		return (100);
	if (strcmp(size_param, "random") == 0)
		return (munit_rand_int_range(1, 1000));
	return (INT32_MAX);
}

static MunitResult	test_insert(const MunitParameter params[], void *data)
{
	(void)params;
	(void)data;
	return (MUNIT_OK);
}

static MunitTest	llist_insert_tests[] = {
	{ "/llist_insert", test_insert, NULL, NULL, MUNIT_TEST_OPTION_NONE, llist_insert_params },
	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

MunitSuite llist_insert_suite = { "llist", llist_insert_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE };