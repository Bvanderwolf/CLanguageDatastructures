#ifndef DLIST_H
# define DLIST_H

# include <stdlib.h>

typedef struct s_dlist
{
	void			*content;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}	t_dlist;

/* Add */

t_dlist	*dlist_new(void *data);
void	dlist_add_front(t_dlist **lst, t_dlist *new);
void	dlist_add_back(t_dlist **lst, t_dlist *new);
void	dlist_insert(t_dlist **lst, t_dlist *new, unsigned int position);

/* Delete */

void	dlist_delone(t_dlist *lst, void (*del)(void *));
void	dlist_clear(t_dlist **lst, void (*del)(void *));

int		dlist_size(t_dlist *lst);
t_dlist	*dlist_last(t_dlist *lst);
t_dlist	*dlist_find(t_dlist *lst, unsigned int position);

#endif