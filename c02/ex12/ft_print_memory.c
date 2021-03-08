/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 10:09:29 by chbadad           #+#    #+#             */
/*   Updated: 2021/02/24 12:07:00 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(unsigned char c)
{
	if (c < 32 || c > 126)
		write(1, ".", 1);
	else
		write(1, &c, 1);
}

void	to_hex(size_t addr)
{
	char *hex;

	hex = "0123456789abcdef";
	if (addr >= 16)
		to_hex(addr / 16);
	ft_putchar(hex[addr % 16]);
}

void	address_to_hex(void *addr)
{
	size_t	cpy;
	size_t	nbr;
	int		count;
	int		remain;

	count = 1;
	cpy = (size_t)addr;
	nbr = cpy;
	while (cpy >= 16)
	{
		cpy /= 16;
		count++;
	}
	remain = 16 - count;
	while (remain--)
		ft_putchar('0');
	to_hex(nbr);
	ft_putchar(':');
}

void	char_to_hex(unsigned char *c, unsigned int size)
{
	char			*hex;
	unsigned int	i;
	unsigned int	n;

	i = 0;
	hex = "0123456789abcdef";
	while (i < size)
	{
		(i % 2 == 0) ? write(1, " ", 1) : write(1, "", 0);
		ft_putchar(hex[c[i] / 16]);
		ft_putchar(hex[c[i] % 16]);
		i++;
	}
	i = 0;
	(size == 16) ? write(1, " ", 1) : write(1, "", 0);
	if (size < 16)
	{
		n = ((16 - size) * 2);
		if (!(size & 1))
			ft_putchar(' ');
		while (n--)
			write(1, "  ", (n % 4 == 0 ? 2 : 1));
	}
	while (i < size)
		ft_putchar(c[i++]);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	print_size;
	char			*add_str;

	add_str = addr;
	i = 0;
	print_size = 16;
	while (i < size)
	{
		print_size = (size - i >= 16) ? 16 : size - i;
		address_to_hex(add_str + i);
		char_to_hex((unsigned char *)add_str + i, print_size);
		write(1, "\n", 1);
		i += 16;
	}
	return (addr);
}
