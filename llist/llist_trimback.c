#include "llist.h"

void	llist_trim_back(t_llist **lst, void (*del)(void *))
{
	t_llist *previous;
	t_llist *current;

	previous = NULL;
	current = *lst;
	while (current != NULL)
	{
		if (current->next == NULL)
			break;
		previous = current;
		current = current->next;
	}
	if (current == *lst)
	{
		llist_delone(*lst, del);
		*lst = NULL;
	}
	else
	{
		previous->next = NULL;
		llist_delone(current, del);
	}
}