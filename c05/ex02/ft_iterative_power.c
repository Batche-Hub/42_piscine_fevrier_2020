/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 10:22:08 by chbadad           #+#    #+#             */
/*   Updated: 2021/02/08 10:22:35 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int count;
	int res;

	res = 1;
	count = 0;
	if (power < 0 || (nb == 0 && power > 0))
		return (0);
	if (power == 0)
		return (1);
	while (count < power)
	{
		res *= nb;
		count++;
	}
	return (res);
}
