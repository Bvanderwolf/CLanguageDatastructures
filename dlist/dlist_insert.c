#include "dlist.h"

void	dlist_insert(t_dlist **lst, t_dlist *new, unsigned int position)
{
	t_dlist	*old;

	old = dlist_find(*lst, position);
	if (position > 1)
	{
		old->prev->next = new;
		old->prev = new;
	}
	else
	{
		old->prev = new;
	}
}
