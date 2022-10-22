#include "llist.h"

void	llist_clear(t_llist **lst, void (*del)(void *))
{
	t_llist	*next;

	while (*lst != NULL)
	{
		next = (*lst)->next;
		llist_delone(*lst, del);
		*lst = next;
	}
}
