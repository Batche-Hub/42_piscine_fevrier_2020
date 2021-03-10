#include <unistd.h>
#include "print_functions.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	error(void)
{
	write(1, "Error\n", 6);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	print_solution(int tab[6][6])
{
	int		x;
	int		y;
	char	c;

	y = 1;
	while (y < 5)
	{
		x = 1;
		while (x < 5)
		{
			c = tab[y][x] + 48;
			write(1, &c, 1);
			write(1, " ", (x != 4) ? 1 : 0);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}
