#include "check_places.h"
#include "init.h"
#include "print_functions.h"
#include "solver.h"
#include <stdlib.h>

int	main(int ac, char **av)
{
	int tab[6][6];

	if (ac == 2)
	{
		make_void_tab(tab);
		if (check_inputs(av[1]) != NULL
				&& is_param_is_correct(check_inputs(av[1])))
		{
			put_people(tab, check_inputs(av[1]));
			if (solve_puzzle(tab, 1, 1))
				print_solution(tab);
			else
				error();
		}
		else
			error();
	}
	else
		error();
	return (0);
}
