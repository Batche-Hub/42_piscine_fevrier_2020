/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 09:42:42 by chbadad           #+#    #+#             */
/*   Updated: 2021/02/15 09:44:16 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_is_sep(char c, char *sep)
{
	while (*sep)
	{
		if (c == *sep)
			return (1);
		sep++;
	}
	return (0);
}

int		nb_wrds(char *str, char *sep)
{
	int count;

	count = 0;
	while (*str)
	{
		while (*str && ft_is_sep(*str, sep))
			str++;
		if (!ft_is_sep(*str, sep) && *str)
		{
			count++;
			while (!ft_is_sep(*str, sep) && *str)
				str++;
		}
	}
	return (count);
}

char	*ft_strdup(char *str, char *sep)
{
	int		i;
	char	*word;

	i = 0;
	while (!ft_is_sep(str[i], sep) && str[i])
		i++;
	if (!(word = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	while (str[i] && !ft_is_sep(str[i], sep))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	char	**tab;

	i = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * nb_wrds(str, charset) + 1)))
		return (NULL);
	while (*str)
	{
		while (*str && ft_is_sep(*str, charset))
			str++;
		if (!ft_is_sep(*str, charset) && *str)
		{
			tab[i] = ft_strdup(str, charset);
			i++;
			while (!ft_is_sep(*str, charset) && *str)
				str++;
		}
	}
	tab[i] = NULL;
	return (tab);
}
