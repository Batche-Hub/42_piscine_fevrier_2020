/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 09:57:40 by chbadad           #+#    #+#             */
/*   Updated: 2021/02/24 12:11:47 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(unsigned char c)
{
	write(1, &c, 1);
}

int		is_no_printable(unsigned char c)
{
	if (c < 32 || c > 126)
		return (1);
	else
		return (0);
}

void	convert_to_hex(unsigned char c)
{
	char *hex;

	hex = "0123456789abcdef";
	ft_putchar('\\');
	ft_putchar(hex[(unsigned char)c / 16]);
	ft_putchar(hex[(unsigned char)c % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (is_no_printable((unsigned char)*str))
			convert_to_hex((unsigned char)*str);
		else
			ft_putchar((unsigned char)*str);
		str++;
	}
}
