/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 16:44:40 by chbadad           #+#    #+#             */
/*   Updated: 2021/02/06 10:05:54 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strncmp(char *s1, char *s2, int i)
{
	int j;

	j = 0;
	while (s1[j] && s2[i])
	{
		if (s1[j] != s2[i])
			return (0);
		i++;
		j++;
	}
	return (1);
}

void	ft_combine(char comb[], int n, int index, int i)
{
	int		j;
	char	*arr;

	arr = "0123456789";
	j = 0;
	if (index == n)
	{
		while (j < n)
		{
			ft_putchar(comb[j]);
			j++;
		}
		write(2, ", ", (!(ft_strncmp(comb, arr, 9 - (n - 1))) ? 2 : 0));
		return ;
	}
	if (i >= 10)
		return ;
	comb[index] = arr[i];
	ft_combine(comb, n, index + 1, i + 1);
	ft_combine(comb, n, index, i + 1);
}

void	ft_print_combn(int n)
{
	char combination[n];

	ft_combine(combination, n, 0, 0);
}

int main()
{
	ft_print_combn(2);
}
