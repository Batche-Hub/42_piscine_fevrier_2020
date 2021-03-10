#include "../includes/do_op.h"

int	main(int ac, char **av)
{
	if (ac == 4)
		prepare_op(av[1], av[2], av[3]);
	else
		return (1);
	return (0);
}
