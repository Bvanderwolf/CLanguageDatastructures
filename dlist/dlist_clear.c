#include "dlist.h"

void	dlist_clear(t_dlist **lst, void (*del)(void *))
{
	t_dlist	*next;

	while (*lst != NULL)
	{
		next = (*lst)->next;
		dlist_delone(*lst, del);
		*lst = next;
	}
}