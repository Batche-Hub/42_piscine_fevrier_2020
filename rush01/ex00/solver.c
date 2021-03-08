/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 14:21:16 by chbadad           #+#    #+#             */
/*   Updated: 2021/02/14 15:04:13 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solver.h"
#include "check_places.h"

int		solve_puzzle(int tab[6][6], int col, int row)
{
	int place;

	place = 1;
	if (col == 5 && row == 4)
	{
		return (check_norm_col(tab) && check_rev_col(tab)
					&& check_norm_row(tab) && check_rev_row(tab));
	}
	(col == 5) ? row++ : row;
	(col == 5) ? col = 1 : col;
	while (place < 5 && col < 5 && row < 5)
	{
		if (is_possible(tab, col, row, place))
		{
			tab[col][row] = place;
			if (solve_puzzle(tab, col + 1, row))
				return (1);
			tab[col][row] = 0;
		}
		place += 1;
	}
	return (0);
}
