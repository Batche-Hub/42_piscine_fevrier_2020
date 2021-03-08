/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:49:56 by chbadad           #+#    #+#             */
/*   Updated: 2021/02/02 14:58:06 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + 48);
}

void	ft_print_comb2(void)
{
	int i;
	int j;

	i = 0;
	while (i <= 98)
	{
		j = i + 1;
		while (j <= 99)
		{
			if (i < 10)
				ft_putchar('0');
			ft_putnbr(i);
			ft_putchar(' ');
			if (j < 10)
				ft_putchar('0');
			ft_putnbr(j);
			if (i != 98)
				write(1, ", ", 2);
			j++;
		}
		i++;
	}
}
