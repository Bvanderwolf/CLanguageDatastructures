#include "dlist.h"

void	dlist_delone(t_dlist *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}