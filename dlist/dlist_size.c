#include "dlist.h"

int		dlist_size(t_dlist *lst)
{
	int		count;
	t_dlist	*current;

	count = 0;
	current = lst;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}
