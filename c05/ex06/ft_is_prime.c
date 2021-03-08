/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 10:46:59 by chbadad           #+#    #+#             */
/*   Updated: 2021/02/08 12:59:18 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int n;

	n = 3;
	if (nb < 0 || nb == 0 || nb == 1)
		return (0);
	if (nb == 2)
		return (1);
	if (!(nb & 1))
		return (0);
	while (n < nb / 2 && n <= 46340)
	{
		if (nb % n == 0 && n != nb)
			return (0);
		n += 2;
	}
	return (1);
}
