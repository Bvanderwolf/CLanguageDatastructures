#include "../../munit/munit.h"
#include "../llist.h"
#include <stdlib.h>

t_llist	*generate_test_list(int size)
{
	t_llist	*lst;
	t_llist	*new;
	int		count;

	count = 0;
	lst = NULL;
	while (count < size)
	{
		new = llist_new(strdup("content"));
		if (new == NULL)
		{
			llist_clear(&lst, &free);
			return (NULL);
		}
		llist_add_back(&lst, new);
		count++;
	}
	return (lst);
}