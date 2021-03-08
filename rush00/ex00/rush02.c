/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 12:37:42 by chbadad           #+#    #+#             */
/*   Updated: 2021/02/07 15:06:45 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	display(int x, int y, char mat[y][x])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			ft_putchar(mat[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	resolve_first(int x, int y, int ord, char mat[y][x])
{
	int abs;

	abs = 0;
	while (abs < x)
	{
		if ((abs == 0 || abs == x - 1) && ord == 0)
			mat[ord][abs] = 'A';
		else if ((abs == 0 || abs == x - 1) && ord == y - 1)
			mat[ord][abs] = 'C';
		else
			mat[ord][abs] = 'B';
		abs++;
	}
}

void	resolve_then(int x, int y, int ord, char mat[y][x])
{
	int abs;

	abs = 0;
	while (abs < x)
	{
		if (abs == 0 || abs == x - 1)
			mat[ord][abs] = 'B';
		else
			mat[ord][abs] = ' ';
		abs++;
	}
}

void	rush(int x, int y)
{
	char	matrice[y][x];
	int		ord;

	if (x < 1 || y < 1)
		return ;
	ord = 0;
	while (ord < y)
	{
		if (ord == 0 || ord == y - 1)
			resolve_first(x, y, ord, matrice);
		else
			resolve_then(x, y, ord, matrice);
		ord++;
	}
	display(x, y, matrice);
}
