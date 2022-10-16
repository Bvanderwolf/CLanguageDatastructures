#include "llist.h"
#include <stdlib.h>

t_llist	*llist_new(void *content)
{
	t_llist	*new;

	new = (t_llist *)malloc(1 * sizeof(t_llist));
	new->content = content;
	new->next = 0;
	return (new);
}
