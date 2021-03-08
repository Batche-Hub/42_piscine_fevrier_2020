# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chbadad <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/16 14:59:18 by chbadad           #+#    #+#              #
#    Updated: 2021/02/17 12:20:02 by chbadad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/sh

gcc -Wall -Wextra -Werror -c ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c
ar rcs libft.a *.o
