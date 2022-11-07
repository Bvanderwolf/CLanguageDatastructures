#include "llist.h"

t_llist	*llist_find(t_llist *lst, unsigned int position)
{
	t_llist			*current;
	unsigned int	count;

	if (position < 1)
		return (NULL);
	if (position == 1)
		return (lst);
	current = lst;
	count = 0U;
	while (count < position && current != NULL)
	{
		count++;
		current = current->next;
	}
	if (count != position)
		return (NULL);
	return (current);
}