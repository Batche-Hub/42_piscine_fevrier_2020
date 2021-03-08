# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chbadad <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/16 16:19:00 by chbadad           #+#    #+#              #
#    Updated: 2021/02/17 12:17:52 by chbadad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
	${GCC} ${CCFLAGS} -c $< -o $@ ($<.c)-I ${INCLUDES}

all: ${OUTPUT}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${OUTPUT}

re: fclean all

.PHONY: all clean fclean re
