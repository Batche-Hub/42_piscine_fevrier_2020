/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 11:47:52 by chbadad           #+#    #+#             */
/*   Updated: 2021/02/09 12:06:40 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

int		main(int ac, char **av)
{
	int		i;
	char	*cpy;

	if (ac > 1)
	{
		i = 1;
		while (i < ac - 1)
		{
			if (ft_strcmp(av[i], av[i + 1]) > 0)
			{
				cpy = av[i];
				av[i] = av[i + 1];
				av[i + 1] = cpy;
				i = 1;
			}
			else
				i++;
		}
		i = 1;
		while (i < ac)
			ft_putstr(av[i++]);
	}
	return (0);
}
