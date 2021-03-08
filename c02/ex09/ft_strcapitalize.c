/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 09:36:32 by chbadad           #+#    #+#             */
/*   Updated: 2021/02/23 16:46:15 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_not_alphanum(char c)
{
	if (!((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')
				|| (c >= 'A' && c <= 'Z')))
		return (1);
	else
		return (0);
}

int		is_upper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}

int		is_lower(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	else
		return (0);
}

int		is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	i = 0;
	while (str[i])
	{
		while (is_not_alphanum(str[i]) && str[i])
			i++;
		if (str[i] && is_lower(str[i]) && is_not_alphanum(str[i - 1])
				&& !is_upper(str[i - 1]) && !is_num(str[i - 1]))
			str[i] -= 32;
		i++;
	}
	return (str);
}
