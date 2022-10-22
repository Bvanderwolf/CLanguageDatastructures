#include "llist.h"

void	llist_add_back(t_llist **lst, t_llist *new)
{
	t_llist	*head;

	head = *lst;
	if (head != NULL)
		llist_last(head)->next = new;
	else
		*lst = new;
}
