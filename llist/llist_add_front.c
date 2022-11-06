#include "llist.h"

void	llist_add_front(t_llist **lst, t_llist *new)
{
	new->next = *lst;
	*lst = new;
}
