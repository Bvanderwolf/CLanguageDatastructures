#include "llist.h"

void	llist_delone(t_llist *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}
