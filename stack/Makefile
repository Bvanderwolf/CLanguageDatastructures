SRC =		 	stack_clear.c stack_new.c stack_pop.c stack_push.c

SRC_LLIST =		${addprefix ${SRC_LLIST_DIR}, \
				llist_clear.c llist_find.c llist_add_back.c llist_new.c llist_delone.c llist_last.c \
				}

TEST_SRC =		tests/test_main.c tests/test_new.c 	../munit/munit.c

SRC_LLIST_DIR = ../llist/

all: ${OBJECTS}
	gcc -Wall -Werror -Wextra ${SRC} ${SRC_LLIST} ${TEST_SRC}