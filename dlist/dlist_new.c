#include "dlist.h"

t_dlist	*dlist_new(void *data)
{
	t_dlist	*new;

	new = (t_dlist *)malloc(1 * sizeof(t_dlist));
	if (new == NULL)
		return (NULL);
	new->data = data;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}