#ifndef STACK_H
# define STACK_H

# include "../llist/llist.h"

typedef struct s_stack
{
	int		size;
	t_llist	*head;
}	t_stack;

int		stack_push(void	*data);
void	*stack_pop();
void	stack_clear();

#endif