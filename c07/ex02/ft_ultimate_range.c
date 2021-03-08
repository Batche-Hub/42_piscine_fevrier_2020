/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 12:30:35 by chbadad           #+#    #+#             */
/*   Updated: 2021/02/15 09:36:06 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int *tab;
	int i;
	int mem;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	else
		mem = max - min;
	if (!(tab = (int *)malloc(sizeof(int) * (max - min))))
	{
		*range = NULL;
		return (-1);
	}
	i = 0;
	while (min < max)
	{
		tab[i] = min;
		i++;
		min++;
	}
	*range = tab;
	return (mem);
}
