
GCC = gcc
RM = rm -f
CCFLAGS = -Wall -Wextra -Werror
SRCS = SRCS/parser.c SRCS/main.c SRCS/utils.c
OBJS = ${SRCS:.c=.o}
OUTPUT = rush-02
INCLUDES = includes

all: ${OUTPUT}

${OUTPUT}: ${OBJS}
	${GCC} ${CCFLAGS} ${OBJS} -o ${OUTPUT}

%.o: %.c
	${GCC} ${CCFLAGS} -c $< -o $@ -I ${INCLUDES}
clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${OUTPUT}

re: fclean all
