#regarder les vidéos sur l'intra (youtube et intra) + ce lien : https://gl.developpez.com/tutoriel/outil/makefile/
GCC = gcc
CCFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRCS = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_swap.c srcs/ft_strcmp.c srcs/ft_strlen.c
OBJS = ${SRCS:.c=.o}
OUTPUT = libft.a
INCLUDES = includes

${OUTPUT}: ${OBJS}
	ar -rcs ${OUTPUT} ${OBJS}

%.o: %.c
	${GCC} ${CCFLAGS} -c $< -o $@ -I ${INCLUDES}

all: ${OUTPUT}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${OUTPUT}

re: fclean all

.PHONY: all clean fclean re
