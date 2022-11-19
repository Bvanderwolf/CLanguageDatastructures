#include "dlist.h"

void	dlist_add_front(t_dlist **lst, t_dlist *new)
{
	t_dlist *head;

	head = *lst;
	if (head != NULL)
		head->prev = new;
	new->next = head;
	new->prev = NULL;
	*lst = new;
}
