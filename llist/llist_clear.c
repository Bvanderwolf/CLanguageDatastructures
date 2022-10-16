#include "llist.h"

void	llist_clear(t_llist **lst, void (*del)(void *))
{
	t_llist	*next;

	while (lst[0] != 0)
	{
		next = lst[0]->next;
		llist_delone(lst[0], del);
		lst[0] = next;
	}
}