#include "dlist.h"

void	dlist_add_back(t_dlist **lst, t_dlist *new)
{
	t_dlist	*last;

	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		last = dlist_last(*lst);
		last->next = new;
		new->prev = last;
		new->next = NULL;
	}
}