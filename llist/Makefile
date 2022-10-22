NAME = llist

SOURCES = ${wildcard *.c}

OBJECTS = ${SOURCES:.c=.o}

RM = rm -r

all: ${OBJECTS}
	gcc -Wall -Werror -Wextra -o ${NAME} ${OBJECTS}

clean:
	${RM} ${OBJECTS}

fclean: clean
	${RM} ${NAME}