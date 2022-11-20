#include "stack.h"

int		stack_push(t_stack *stack, void	*content)
{
	t_llist	*new;

	new = llist_new(content);
	if (new == NULL)
		return (0);
	llist_add_back(&(stack->head), new);
	stack->size++;
	return (1);
}