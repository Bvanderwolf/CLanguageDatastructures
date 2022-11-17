#include "../../munit/munit.h"
#include "../llist.h"
#include "test_llist.h"
#include <stdlib.h>
#include <stdio.h>

static char	*size_params[] = {
	"0", "1", "25", "100", "random", NULL
};

static char	*position_params[] = {
	"-1", "0", "1", "25", "100", NULL
};

static MunitParameterEnum	llist_find_params[] = {
	{ "size", size_params },
	{ "position", position_params },
	{ NULL, NULL }
};

int	get_position_value(const char *pos_param)
{
	if (strcmp(pos_param, "-1") == 0)
		return (-1);
	if (strcmp(pos_param, "0") == 0)
		return (0);
	if (strcmp(pos_param, "1") == 0)
		return (1);
	if (strcmp(pos_param, "25") == 0)
		return (25);
	if (strcmp(pos_param, "100") == 0)
		return (100);
	return (INT32_MAX);
}

int	get_size_value(const char *size_param)
{
	if (strcmp(size_param, "0") == 0)
		return (0);
	if (strcmp(size_param, "1") == 0)
		return (1);
	if (strcmp(size_param, "25") == 0)
		return (25);
	if (strcmp(size_param, "100") == 0)
		return (100);
	if (strcmp(size_param, "random") == 0)
		return (munit_rand_int_range(1, 1000));
	return (INT32_MAX);
}

static MunitResult	test_position_one(int size, int position)
{
	t_llist	*lst;
	t_llist	*actual;
	t_llist	*expected;

	lst = generate_test_list(size);
	actual = llist_find(lst, position);
	expected = lst;
	munit_assert_ptr_equal(actual, expected);
	llist_clear(&lst, &free);
	return (MUNIT_OK);
}

static MunitResult	test_position_smaller_then_one(int size, int position)
{
	t_llist	*lst;
	t_llist	*actual;

	lst = generate_test_list(size);
	actual = llist_find(lst, position);
	munit_assert_ptr_null(actual);
	llist_clear(&lst, &free);
	return (MUNIT_OK);
}

static MunitResult	test_early_return(int size, int position)
{
	if (position < 1)
		return (test_position_smaller_then_one(size, position));
	if (position == 1)
		return (test_position_one(size, position));
	return (MUNIT_ERROR);
}

static MunitResult	test_out_of_bounds(int size, int position)
{
	t_llist	*lst;
	t_llist	*actual;

	lst = generate_test_list(size);
	actual = llist_find(lst, position);
	munit_assert_ptr_null(actual);
	llist_clear(&lst, &free);
	return (MUNIT_OK);
}

static MunitResult	test_within_bounds(int size, int position)
{
	t_llist		*lst;
	t_llist		*new;
	t_llist		*expected;
	t_llist		*actual;
	int			count;

	lst = NULL;
	count = 0;
	while (count < size)
	{
		new = llist_new(strdup("content"));
		if (new == NULL)
		{
			llist_clear(&lst, &free);
			return (MUNIT_ERROR);
		}
		llist_add_back(&lst, new);
		count++;
		if (count == position)
			expected = new;
	}
	actual = llist_find(lst, position);
	munit_assert_ptr_equal(actual, expected);
	llist_clear(&lst, &free);
	return (MUNIT_OK);
}

static MunitResult	test_find(const MunitParameter params[], void* data)
{
	const char	*size_param;
	const char	*pos_param;
	int			size_value;
	int			pos_value;

	(void)data;
	size_param = munit_parameters_get(params, "size");
	pos_param = munit_parameters_get(params, "position");
	if (size_param == NULL || pos_param == NULL)
		return (MUNIT_SKIP);
	size_value = get_size_value(size_param);
	pos_value = get_position_value(pos_param);
	if (size_value == INT32_MAX || pos_value == INT32_MAX)
		return (MUNIT_ERROR);
	if (pos_value <= 1)
		return (test_early_return(size_value, pos_value));
	if (pos_value > size_value)
		return (test_out_of_bounds(size_value, pos_value));
	test_within_bounds(size_value, pos_value);
	return (MUNIT_OK);
}

static MunitTest	llist_find_tests[] = {
	{ "/llist_find", test_find, NULL, NULL, MUNIT_TEST_OPTION_NONE, llist_find_params },
	{ NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

MunitSuite llist_find_suite = { "llist", llist_find_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE };
