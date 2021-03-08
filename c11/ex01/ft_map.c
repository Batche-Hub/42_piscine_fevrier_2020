/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 10:24:52 by chbadad           #+#    #+#             */
/*   Updated: 2021/02/21 10:33:18 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int *res;
	int i;

	i = -1;
	if (!(res = (int *)malloc(sizeof(int) * length)))
		return (NULL);
	while (++i < length)
		res[i] = (*f)(tab[i]);
	return (res);
}
