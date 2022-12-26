#include "llist.h"

void	llist_insert(t_llist **lst, t_llist *new, unsigned int position)
{
	t_llist	*previous;
	t_llist	*next;

	if (position > 1)
	{
		previous = llist_find(*lst, position - 1);
		next = previous->next;
		previous->next = new;
	}
	else
	{
		next = *lst;
		*lst = new;
	}
	new->next = next;
}
