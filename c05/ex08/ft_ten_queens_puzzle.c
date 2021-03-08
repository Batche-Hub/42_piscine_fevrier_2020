/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 14:33:06 by chbadad           #+#    #+#             */
/*   Updated: 2021/02/08 16:13:13 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_puzzle(int board[10])
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = board[i] + 48;
		write(1, &c, 1);
		i++;
		if (i == 10)
			write(1, "\n", 1);
	}
}

int		ft_abs(int n)
{
	return ((n < 0) ? n *= -1 : n);
}

int		staying_safe(int board[10], int column, int row)
{
	int left;

	left = column - 1;
	while (left >= 0 && column != 0)
	{
		if (board[left] == row + ft_abs(left - column))
			return (0);
		if (board[left] == row - ft_abs(left - column))
			return (0);
		if (board[left] == row)
			return (0);
		left--;
	}
	return (1);
}

int		solve_puzzle(int board[10], int column, int *victory)
{
	int row;

	row = 0;
	if (column == 10)
	{
		print_puzzle(board);
		*victory += 1;
		return (1);
	}
	while (row < 10)
	{
		if (staying_safe(board, column, row))
		{
			board[column] = row;
			solve_puzzle(board, column + 1, victory);
			board[column] = -1;
		}
		row += 1;
	}
	return (0);
}

int		ft_ten_queens_puzzle(void)
{
	int victory;
	int board[10];
	int column;

	column = 0;
	victory = 0;
	solve_puzzle(board, column, &victory);
	return (victory);
}
