#include "stack.h"

// test case: () -> t_stack*

t_stack	*stack_new(void)
{
	t_stack	*stack;

	stack = malloc(1 * sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->size = 0;
	stack->head = NULL;
	return (stack);
}