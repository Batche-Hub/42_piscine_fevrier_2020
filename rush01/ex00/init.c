/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfrancoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 13:15:08 by tfrancoi          #+#    #+#             */
/*   Updated: 2021/02/14 17:06:19 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "init.h"
#include "print_functions.h"

void	make_void_tab(int tab[6][6])
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < 6)
	{
		x = 0;
		while (x < 6)
		{
			tab[y][x] = 0;
			x++;
		}
		y++;
	}
}

char	*check_inputs(char *inputs)
{
	int		i;
	int		j;
	char	*export;

	if (ft_strlen(inputs) != 31)
		return (NULL);
	i = 0;
	j = 0;
	if (!(export = (char *)malloc(sizeof(char) * 17)))
		return (NULL);
	while (inputs[i])
	{
		if ((inputs[i] < '1' || inputs[i] > '4') && inputs[i] != ' ')
			return (NULL);
		else if (!(i & 1))
		{
			export[j] = inputs[i];
			j++;
		}
		i++;
	}
	export[j] = 0;
	return (export);
}

int		is_param_is_correct(char *param)
{
	if (ft_strlen(param) != 16)
		return (0);
	while (*param)
	{
		if (*param < '1' || *param > '4')
			return (0);
		param++;
	}
	return (1);
}

void	put_people(int tab[6][6], char *people)
{
	int i;
	int x;
	int y;

	i = 0;
	y = 0;
	while (y < 6)
	{
		x = 0;
		while (x++ < 4)
			tab[y][x] = (int)people[i++] - 48;
		y += 5;
	}
	x = 0;
	while (x < 6)
	{
		y = 0;
		while (y++ < 4)
			tab[y][x] = (int)people[i++] - 48;
		x += 5;
	}
}
