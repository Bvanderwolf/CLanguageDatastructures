#include "stack.h"

// test case: (NULL, "") 				-> Segfault
// test case: (stack[0], NULL) 			-> stack[1] {NULL}
// test case: (stack[0], "")			-> stack[1] {""}
// test case: (stack[1]{"a"}, "b")		-> stack[2] {"a", "b"}
// test case: (stack[2]{"a", "b"}, "c")	-> stack[3] {"a", "b", "c"}

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