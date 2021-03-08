/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 13:04:20 by chbadad           #+#    #+#             */
/*   Updated: 2021/02/09 11:15:03 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int n;

	n = 3;
	if (nb < 2)
		return (0);
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

int	ft_find_next_prime(int nb)
{
	int nbr;

	nbr = nb;
	if (nb <= 2)
		return (2);
	if (ft_is_prime(nbr))
		return (nbr);
	if (!(nbr & 1))
		nbr += 1;
	while (!ft_is_prime(nbr))
		nbr += 2;
	return (nbr);
}
