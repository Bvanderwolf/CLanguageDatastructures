#include "../../munit/munit.h"
#include "../llist.h"
#include <stdlib.h>

extern MunitSuite llist_size_suite;

int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
	MunitSuite suites[] = { llist_size_suite };
	const MunitSuite main_suite = { "llist", NULL, suites, 1, MUNIT_SUITE_OPTION_NONE };
  	return munit_suite_main(&main_suite, NULL, argc, argv);
}