//voir ex00
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

int		main(int ac, char **av)
{
	int i;

	if (ac > 1)
	{
		i = ac - 1;
		while (i > 0)
			ft_putstr(av[i--]);
	}
	return (0);
}
