#include "llist.h"

t_llist	*llist_map(t_llist *lst, void *(*f)(void *), void (*del)(void *))
{
	t_llist *head;
	t_llist *new;

	while (lst != NULL)
	{
		new = llist_new(f(lst->content));
		if (new == NULL)
		{
			llist_clear(&head, del);
			return (NULL);
		}
		llist_add_back(&head, new);
		lst = lst->next;
	}
	return (head);
}
