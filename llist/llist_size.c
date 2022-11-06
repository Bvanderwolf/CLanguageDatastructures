#include "llist.h"

int		llist_size(t_llist *lst)
{
	int		count;
	t_llist	*current;

	count = 0;
	current = lst;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return (count);
}
