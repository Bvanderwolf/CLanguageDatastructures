#include "../../munit/munit.h"
#include "../stack.h"
#include <stdlib.h>

extern MunitSuite stack_new_suite;

static MunitSuite llist_suite_terminator = { NULL, NULL, NULL, 0, MUNIT_SUITE_OPTION_NONE };

int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) 
{
	MunitSuite suites[] = {
		stack_new_suite, llist_suite_terminator 
	};
	const MunitSuite main_suite = { NULL, NULL, suites, 1, MUNIT_SUITE_OPTION_NONE };
  	return munit_suite_main(&main_suite, NULL, argc, argv);
}