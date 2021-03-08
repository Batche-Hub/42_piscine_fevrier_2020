/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 11:39:05 by chbadad           #+#    #+#             */
/*   Updated: 2021/02/21 11:40:49 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *str, char *to_comp)
{
	int i;

	i = 0;
	while (str[i] && str[i] == to_comp[i])
		i++;
	return (str[i] - to_comp[i]);
}

int		ft_tablen(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	ft_sort_string_tab(char **tab)
{
	int		i;
	int		len;
	char	*temp;

	len = ft_tablen(tab);
	i = 0;
	while (i < len - 1)
	{
		if (ft_strcmp(tab[i], tab[i + 1]) > 0)
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}
