#include "llist.h"

void	llist_trim_front(t_llist **lst, void (*del)(void *))
{
	t_llist *next;

	next = (*lst)->next;
	llist_delone(*lst, del);
	*lst = next;
}