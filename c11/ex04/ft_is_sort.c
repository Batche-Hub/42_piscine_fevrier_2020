/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 12:32:36 by chbadad           #+#    #+#             */
/*   Updated: 2021/02/21 10:43:47 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int asc;
	int desc;

	i = 0;
	asc = 0;
	desc = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			asc = 1;
		else if (f(tab[i], tab[i + 1]) > 0)
			desc = 1;
		if (desc != 0 && asc != 0 && desc == asc)
			return (0);
		i++;
	}
	return (1);
}
