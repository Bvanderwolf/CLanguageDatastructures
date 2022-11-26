#include "../../munit/munit.h"
#include "../stack.h"
#include <stdlib.h>

static char	*params[] = {
	"new", NULL
};

static MunitParameterEnum stack_new_params[] = {
	{ "value", params },
	{ NULL, NULL }
};

static MunitResult test_new(const MunitParameter params[], void *data)
{
	t_stack	*stack;

	(void)params;
	(void)data;
	stack = stack_new();
	munit_assert_ptr_not_null(stack);
	if (stack != NULL)
		free(stack);
	return (MUNIT_OK);
}

static MunitTest stack_new_tests[] = {
	{ "/stack_new", test_new, NULL, NULL, MUNIT_TEST_OPTION_NONE, stack_new_params },
	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

MunitSuite stack_new_suite = { "stack", stack_new_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE };
