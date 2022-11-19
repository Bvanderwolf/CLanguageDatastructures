#ifndef DLIST_H
# define DLIST_H

# include <stdlib.h>

typedef struct s_dlist
{
	void	*data;
	t_dlist	*next;
	t_dlist	*prev;
}	t_dlist;

t_dlist	*dlist_new(void *data);

int		dlist_size(t_dlist *lst);
t_dlist	*llist_last(t_dlist *lst);
t_dlist	*llist_find(t_dlist *lst, unsigned int position);

#endif