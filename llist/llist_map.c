#include "llist.h"

t_llist	*llist_map(t_llist *lst, void *(*f)(void *), void (*del)(void *))
{
	t_llist	*old_head;
	t_llist	*old;
	t_llist	*new;

	old_head = lst;
	new = llist_new(f(old_head->content));
	while (old_head != 0)
	{
		old = old_head;
		old_head = old_head->next;
		llist_delone(old, del);
		llist_add_back(new, llist_new(old_head->content));
	}
	return (new);
}
