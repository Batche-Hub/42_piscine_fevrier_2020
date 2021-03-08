/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 15:42:32 by chbadad           #+#    #+#             */
/*   Updated: 2021/02/15 09:42:18 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strempty(void)
{
	char *concat;

	concat = (char *)malloc(sizeof(char));
	*concat = 0;
	return (concat);
}

char	*ft_strcat(char *dest, char *src, char *sep, int count)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (dest[i])
		i++;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	if (count > 0)
	{
		while (sep[k])
		{
			dest[i + j + k] = sep[k];
			k++;
		}
	}
	dest[i + j + k] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		lens_size;
	int		count;
	char	*concat;

	if (size <= 0)
		return (ft_strempty());
	i = 0;
	lens_size = 0;
	while (i < size)
		lens_size += ft_strlen(strs[i++]);
	lens_size += ft_strlen(sep) * (size - 1);
	if (!(concat = (char *)malloc(sizeof(char) * lens_size + 1)))
		return (NULL);
	i = 0;
	count = size - 1;
	concat[i] = 0;
	while (i < size)
	{
		ft_strcat(concat, strs[i], sep, count);
		i++;
		count--;
	}
	return (concat);
}
