# pas très compliqué, regardez les vidéo de l'intra, c'est copié/collé ou quasi.
#!/bin/sh

gcc -Wall -Wextra -Werror -c ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c
ar rcs libft.a *.o
