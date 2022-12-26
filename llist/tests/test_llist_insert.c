#include "../../munit/munit.h"
#include "../llist.h"
#include "test_llist.h"
#include <stdlib.h>

static void *setup(const MunitParameter params[], void *user_data)
{
	(void)params;
	(void)user_data;
    return (generate_test_list(3));
}

static void tear_down(void *fixture)
{
	t_llist *next;
    t_llist *head;

	head = (t_llist *)fixture;
    while (head != NULL)
    {
        next = head->next;
        free(head);
        head = next;
    }
}

static char	*position_params[] = {
	"start", "middle", "end", NULL
};

static MunitParameterEnum	llist_insert_params[] = {
	{ "position", position_params },
	{ NULL, NULL }
};

static int	get_position_value(const char *pos_param)
{
	if (strcmp(pos_param, "start") == 0)
		return (1);
	if (strcmp(pos_param, "middle") == 0)
		return (2);
	if (strcmp(pos_param, "end") == 0)
		return (3);
	return (INT32_MAX);
}

static MunitResult	test_insert_at_position(t_llist *head, int position)
{
	t_llist *new;
	t_llist	*actual;
	int		i;

	new = llist_new("target");
	if (new == NULL)
		return (MUNIT_ERROR);
	llist_insert(&head, new, position);
	actual = head;
	i = 0;
	while (i < position - 1)
	{
		actual = actual->next;
		i++;
	}
	munit_assert_string_equal(actual->content, new->content);
	return (MUNIT_OK);
}

static MunitResult	test_insert(const MunitParameter params[], void *data)
{
	const char	*pos_param;
	int			pos_value;
	t_llist		*head;

	head = (t_llist *)data;
	pos_param = munit_parameters_get(params, "position");
	if (pos_param == NULL)
		return (MUNIT_SKIP);
	pos_value = get_position_value(pos_param);
	if (pos_value == INT32_MAX)
		return (MUNIT_ERROR);
	return (test_insert_at_position(head, pos_value));
}

static MunitTest	llist_insert_tests[] = {
	{ "/llist_insert", test_insert, setup, tear_down, MUNIT_TEST_OPTION_NONE, llist_insert_params },
	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

MunitSuite llist_insert_suite = { "llist", llist_insert_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE };