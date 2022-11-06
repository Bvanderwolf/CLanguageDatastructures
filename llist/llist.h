#ifndef LLIST_H
# define LLIST_H

#include <stdlib.h>

typedef struct s_llist
{
	void	*content;
	struct s_llist	*next;
}			t_llist;

t_llist	*llist_new(void *content);
void	llist_add_front(t_llist **lst, t_llist *new);
int		llist_size(t_llist *lst);
t_llist	*llist_last(t_llist *lst);
void	llist_add_back(t_llist **lst, t_llist *new);
void	llist_insert(t_llist **lst, t_llist *new, unsigned int position);
void	llist_delone(t_llist *lst, void (*del)(void *));
void	llist_clear(t_llist **lst, void (*del)(void *));
void	llist_iter(t_llist *lst, void (*f)(void *));
t_llist	*llist_map(t_llist *lst, void *(*f)(void *), void (*del)(void *));

#endif