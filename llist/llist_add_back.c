#include "llist.h"

void	llist_add_back(t_llist **lst, t_llist *new)
{
	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		llist_last(*lst)->next = new;
		new->next = NULL;
	}
}
