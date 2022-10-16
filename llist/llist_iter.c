#include "llist.h"

void	llist_iter(t_llist *lst, void (*f)(void *))
{
	t_llist	*current;

	current = lst;
	while (current != 0)
	{
		f(current);
		current = current->next;
	}
}