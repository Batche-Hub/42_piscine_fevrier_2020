/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 11:59:35 by chbadad           #+#    #+#             */
/*   Updated: 2021/02/07 12:01:21 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_baselen(char *base)
{
	int i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n' || c == '\r'
			|| c == '\f' || c == '\v' || c == '\t')
		return (1);
	return (0);
}

int	check_base(char *base)
{
	int i;
	int j;

	if (ft_baselen(base) <= 1)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || ft_isspace(base[i]))
			return (0);
		i++;
	}
	i = 0;
	while (base[i] && i < ft_baselen(base))
	{
		j = ft_baselen(base) - 1;
		while (j > i)
		{
			if (base[i] == base[j])
				return (0);
			j--;
		}
		i++;
	}
	return (1);
}

int	int_from_base(char *base, char c)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int res;
	int sign;
	int baselen;

	res = 0;
	sign = 1;
	baselen = ft_baselen(base);
	if (!check_base(base))
		return (0);
	while (*str && ft_isspace(*str))
		str++;
	while (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str && int_from_base(base, *str) != -1)
	{
		res = res * baselen + int_from_base(base, *str);
		str++;
	}
	return (res * sign);
}

int main()
{
    char *str = "      +-+-+-asfefsef";
    char *base = "0123456789abcdef";
    printf("%d", ft_atoi_base(str, base));
}
