C_FLAGS = -Wall -Wextra -Werror

SRC =		llist_add_back.c llist_add_front.c llist_insert.c \
			llist_clear.c llist_delone.c llist_remove_at.c llist_trimback.c llist_trimfront.c \
			llist_iter.c llist_last.c llist_map.c \
			llist_new.c llist_size.c llist_find.c  

TEST_SRC = 	tests/test_llist_size.c tests/test_llist_new.c tests/test_llist_last.c \
			tests/test_llist_find.c tests/test_llist_add_front.c tests/test_llist_add_back.c \
			tests/test_llist_insert.c \
			tests/test_main.c \
			tests/test_utils.c \
			../munit/munit.c

LIB = ar -rcs

CC = cc

NAME = llist.a

RM = rm -f

OBJS = ${SRC:.c=.o}

run:
	gcc ${C_FLAGS} ${SRC} ${TEST_SRC} && ./a.out

archive: ${NAME}

.c.o:
			${CC} ${C_FLAGS} -c $< -o ${<:.c=.o}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

${NAME}:	${OBJS}
			${LIB} ${NAME} ${OBJS}

.PHONY:		all clean fclean re
