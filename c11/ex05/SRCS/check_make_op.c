/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_make_op.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 10:45:07 by chbadad           #+#    #+#             */
/*   Updated: 2021/02/21 11:35:00 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/do_op.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2", 2);
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + 48);
}

int		ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
			|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int		ft_atoi(char *str)
{
	int res;
	int sign;

	res = 0;
	sign = 1;
	while (*str && ft_isspace(*str))
		str++;
	while (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - 48;
		str++;
	}
	return (res * sign);
}
