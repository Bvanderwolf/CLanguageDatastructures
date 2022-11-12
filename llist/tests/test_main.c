#include "../../munit/munit.h"
#include "../llist.h"
#include <stdlib.h>

extern MunitSuite llist_size_suite;
extern MunitSuite llist_new_suite;
extern MunitSuite llist_last_suite;

static MunitSuite llist_suite_terminator = { NULL, NULL, NULL, 0, MUNIT_SUITE_OPTION_NONE };

int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) 
{
	MunitSuite suites[] = { llist_size_suite, llist_new_suite, llist_last_suite, llist_suite_terminator };
	const MunitSuite main_suite = { NULL, NULL, suites, 1, MUNIT_SUITE_OPTION_NONE };
  	return munit_suite_main(&main_suite, NULL, argc, argv);
}