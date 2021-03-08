/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:33:47 by chbadad           #+#    #+#             */
/*   Updated: 2021/02/09 12:06:25 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

int		main(int ac, char **av)
{
	int i;

	if (ac > 1)
	{
		i = ac - 1;
		while (i > 0)
			ft_putstr(av[i--]);
	}
	return (0);
}
