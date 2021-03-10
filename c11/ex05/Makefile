#le makefile
GCC = gcc
RM = rm -f
CCFLAGS = -Wall -Wextra -Werror
SRCS = SRCS/check_make_op.c SRCS/main.c SRCS/do_op.c SRCS/operations.c
OBJS = ${SRCS:.c=.o}
OUTPUT = do-op
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
