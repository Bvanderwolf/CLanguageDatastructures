SRC =		llist_add_back.c llist_add_front.c llist_insert.c \
			llist_clear.c llist_delone.c llist_remove_at.c llist_trimback.c llist_trimfront.c \
			llist_iter.c llist_last.c llist_map.c \
			llist_new.c llist_size.c llist_find.c  

TEST_SRC = 	tests/test_llist_size.c tests/test_llist_new.c tests/test_llist_last.c \
			tests/test_llist_find.c \
			tests/test_main.c \
			../munit/munit.c

all: ${OBJECTS}
	gcc -Wall -Werror -Wextra ${SRC} ${TEST_SRC}
