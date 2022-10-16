#include "llist.h"

t_llist	*llist_last(t_llist *lst)
{
	t_llist	*last;

	last = lst;
	while (last->next != 0)
		last = last->next;
	return (last);
}
