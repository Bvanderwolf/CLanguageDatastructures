#include "dlist.h"

t_dlist	*llist_last(t_dlist *lst)
{
	t_dlist	*last;

	last = lst;
	while (last != NULL)
	{
		if (last->next == NULL)
			return (last);
		last = last->next;
	}
	return (last);
}