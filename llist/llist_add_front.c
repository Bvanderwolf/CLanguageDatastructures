#include "llist.h"

void	llist_add_front(t_llist **lst, t_llist *new)
{
	t_llist *head;

	head = *lst;
	new->next = head;
	*lst = new;
}
