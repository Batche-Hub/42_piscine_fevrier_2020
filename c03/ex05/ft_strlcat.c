/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 08:58:33 by chbadad           #+#    #+#             */
/*   Updated: 2021/02/05 16:10:56 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int src_len;
	unsigned int dest_len;
	unsigned int i;

	i = 0;
	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (size >= dest_len)
		src_len += dest_len;
	else
		src_len += size;
	if (size > dest_len)
	{
		while (src[i] && dest_len < size - 1)
		{
			dest[dest_len] = src[i];
			dest_len++;
			i++;
		}
	}
	dest[dest_len] = '\0';
	return (src_len);
}
