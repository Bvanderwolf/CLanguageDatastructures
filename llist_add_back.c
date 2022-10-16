#include "llist.h"

void	llist_add_back(t_llist **lst, t_llist *new)
{
	t_llist	*head;
	t_llist *last;

	head = lst[0];
	if (head != 0)
		llist_last(head)->next = new;
	else
		lst[0] = new;
}
