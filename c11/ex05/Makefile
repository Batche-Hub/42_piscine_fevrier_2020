# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chbadad <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/16 16:19:00 by chbadad           #+#    #+#              #
#    Updated: 2021/02/21 10:44:35 by chbadad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
