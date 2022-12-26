#include "../../munit/munit.h"
#include "../stack.h"
#include <stdlib.h>

static char	*params[] = {
	"0", "1", "2", NULL
};

static MunitParameterEnum stack_new_params[] = {
	{ "size", params },
	{ NULL, NULL }
};

static t_stack	*create_stack(int size)
{
	int		i;
	t_stack	*stack;

	stack = stack_new();
	i = 0;
	while (i < size)
	{
		stack_push(stack, strdup("content"));
		i++;
	}
	return (stack);
}

static MunitResult	test_stack_size(int size)
{
	t_stack	*stack;


	return (MUNIT_OK);
}

static MunitResult	test_pop(const MunitParameter params[], void *data)
{
	const char	*param;

	param = munit_parameters_get(params, "size");
	if (param == NULL)
		return (MUNIT_SKIP);
	if (strcmp(param, "0") == 0)
		return (test_stack_size(0));
	if (strcmp(param, "1") == 0)
		return (test_stack_size(1));
	if (strcmp(param, "2") == 0)
		return (test_stack_size(2));
	return (MUNIT_ERROR);
}

static MunitTest stack_pop_tests[] = {
	{ "/stack_new", test_pop, NULL, NULL, MUNIT_TEST_OPTION_NONE, stack_new_params },
	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

MunitSuite stack_new_suite = { "stack", stack_pop_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE };