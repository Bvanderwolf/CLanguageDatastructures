#include "llist.h"

t_llist	*llist_last(t_llist *lst)
{
	t_llist	*last;

	last = lst;
	while (last != NULL)
	{
		if (last->next == NULL)
			return (last);
		last = last->next;
	}
	return (last);
}
