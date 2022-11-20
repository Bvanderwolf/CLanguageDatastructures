#include "stack.h"

void	*stack_pop(t_stack *stack)
{
	void	*content;
	t_llist	*second_last;

	if (stack->size == 0)
		return (NULL);
	if (stack->size == 1)
	{
		content = stack->head->content;
		free(stack->head);
		stack->head = NULL;
	}
	else
	{
		second_last = llist_find(stack->head, stack->size - 1);
		content = second_last->next->content;
		free(second_last->next);
		second_last->next = NULL;
	}
	return (content);
}