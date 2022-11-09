#include "llist.h"

void	llist_remove_at(t_llist **lst, void (*del)(void *), unsigned int position)
{
	t_llist	*previous;
	t_llist *next;

	if (position > 1)
	{
		previous = llist_find(*lst, position - 1);
		next = previous->next;
		previous->next = next->next;
		llist_delone(next, del);
	}
	else
	{
		next = (*lst)->next;
		llist_delone(*lst, del);
		*lst = next;
	}
}