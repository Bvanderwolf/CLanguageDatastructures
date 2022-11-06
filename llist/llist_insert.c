#include "llist.h"

void	llist_insert(t_llist **lst, t_llist *new, unsigned int position)
{
	unsigned int	count;
	t_llist			*current;
	t_llist			*previous;

	count = 0;
	current = lst[0];
	while (current != 0 && count < position)
	{
		count++;
		if (count == position)
		{
			if (previous != NULL)
				previous->next = new;
			new->next = current;
		}
		previous = current;
		current = current->next;
	}
	if (position == 1)
		lst[0] = new;
}
