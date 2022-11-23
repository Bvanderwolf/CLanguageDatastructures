#include "stack.h"

// test case: (NULL, &free)		-> Segfault
// test case: (lst[5], NULL)	-> Segfault
// test case: (lst[0], &free)	-> []
// test case: (lst[1], &free)	-> []
// test case: (lst[5], &free)	-> []

void	stack_clear(t_stack *stack, void (*del)(void *))
{
	llist_clear(&(stack->head), del);
	stack->size = 0;
}
