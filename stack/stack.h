#ifndef STACK_H
# define STACK_H

# include "../llist/llist.h"

typedef struct s_stack
{
	int		size;
	t_llist	*head;
}	t_stack;

t_stack	*stack_new();
int		stack_push(t_stack *stack, void	*content);
void	*stack_pop(t_stack *stack);
void	stack_clear(t_stack *stack);

#endif