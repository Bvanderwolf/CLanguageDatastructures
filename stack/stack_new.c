#include "stack.h"

t_stack	*stack_new()
{
	t_stack	*stack;

	stack = malloc(1 * sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->size = 0;
	stack->head = NULL;
	return (stack);
}