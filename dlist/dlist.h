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
void	dlist_add_front(t_dlist **lst, t_dlist *new);
void	dlist_add_back(t_dlist **lst, t_dlist *new);

int		dlist_size(t_dlist *lst);
t_dlist	*dlist_last(t_dlist *lst);
t_dlist	*dlist_find(t_dlist *lst, unsigned int position);

#endif