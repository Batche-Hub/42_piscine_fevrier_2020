/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_places.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 14:14:06 by chbadad           #+#    #+#             */
/*   Updated: 2021/02/14 14:52:57 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_places.h"

int	check_norm_col(int tab[6][6])
{
	int x;
	int y;
	int count;
	int max;

	x = 1;
	while (x < 5)
	{
		y = 1;
		max = tab[y][x];
		count = 1;
		while (y < 5)
		{
			if (tab[y][x] > max)
			{
				count++;
				max = tab[y][x];
			}
			y++;
		}
		if (tab[0][x] != count)
			return (0);
		x++;
	}
	return (1);
}

int	check_rev_col(int tab[6][6])
{
	int x;
	int y;
	int count;
	int max;

	x = 4;
	while (x > 0)
	{
		y = 4;
		count = 1;
		max = tab[y][x];
		while (y > 0)
		{
			if (tab[y][x] > max)
			{
				count++;
				max = tab[y][x];
			}
			y--;
		}
		if (tab[5][x] != count)
			return (0);
		x--;
	}
	return (1);
}

int	check_norm_row(int tab[6][6])
{
	int x;
	int y;
	int count;
	int max;

	y = 1;
	while (y < 5)
	{
		x = 1;
		count = 1;
		max = tab[y][x];
		while (x < 5)
		{
			if (tab[y][x] > max)
			{
				count++;
				max = tab[y][x];
			}
			x++;
		}
		if (tab[y][0] != count)
			return (0);
		y++;
	}
	return (1);
}

int	check_rev_row(int tab[6][6])
{
	int x;
	int y;
	int count;
	int max;

	y = 4;
	while (y > 0)
	{
		x = 4;
		count = 1;
		max = tab[y][x];
		while (x > 0)
		{
			if (tab[y][x] > max)
			{
				count++;
				max = tab[y][x];
			}
			x--;
		}
		if (tab[y][5] != count)
			return (0);
		y--;
	}
	return (1);
}

int	is_possible(int tab[6][6], int col, int row, int place)
{
	int col_down;
	int row_left;

	col_down = col - 1;
	row_left = row - 1;
	if (row != 0 && row != 1 && row != 5 && col != 0 && col != 5)
	{
		while (row_left > 0)
		{
			if (tab[col][row_left] == place)
				return (0);
			row_left--;
		}
	}
	if (col != 0 && col != 1 && col != 5 && row != 0 && row != 5)
	{
		while (col_down > 0)
		{
			if (tab[col_down][row] == place)
				return (0);
			col_down--;
		}
	}
	return (1);
}
