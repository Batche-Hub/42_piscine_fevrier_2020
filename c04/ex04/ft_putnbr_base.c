/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 13:40:24 by chbadad           #+#    #+#             */
/*   Updated: 2021/02/07 11:25:24 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_baselen(char *base)
{
	int i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int		check_base(char *base)
{
	int i;
	int j;

	if (ft_baselen(base) <= 1)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	i = 0;
	while (base[i] && i < ft_baselen(base))
	{
		j = ft_baselen(base) - 1;
		while (j > i)
		{
			if (base[i] == base[j])
				return (0);
			j--;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	nb;
	int		baselen;

	nb = (long)nbr;
	if (!check_base(base))
		return ;
	baselen = ft_baselen(base);
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb >= baselen)
		ft_putnbr_base(nb / baselen, base);
	ft_putchar(base[nb % baselen]);
}
