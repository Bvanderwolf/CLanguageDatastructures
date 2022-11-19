#include "dlist.h"

t_dlist	*llist_find(t_dlist *lst, unsigned int position)
{
	t_dlist			*current;
	unsigned int	count;

	if (position < 1)
		return (NULL);
	if (position == 1)
		return (lst);
	current = lst;
	count = 1U;
	while (count < position && current != NULL)
	{
		count++;
		current = current->next;
	}
	if (count == position)
		return (current);
	return (NULL);
}