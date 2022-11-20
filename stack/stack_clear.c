#include "stack.h"

void	stack_clear(t_stack *stack, void (*del)(void *))
{
	llist_clear(&(stack->head), del);
	stack->size = 0;
}
