/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 11:12:49 by chbadad           #+#    #+#             */
/*   Updated: 2021/02/21 11:35:23 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/do_op.h"

int		check_op(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	if (i != 1)
		return (-1);
	else if (*str == '+')
		return (0);
	else if (*str == '-')
		return (1);
	else if (*str == '*')
		return (2);
	else if (*str == '/')
		return (3);
	else if (*str == '%')
		return (4);
	else
		return (-1);
}

void	prepare_op(char *num1, char *operande, char *num2)
{
	int operator;
	int number1;
	int number2;

	operator = check_op(operande);
	number1 = ft_atoi(num1);
	number2 = ft_atoi(num2);
	if (operator == -1)
	{
		write(1, "0\n", 2);
		return ;
	}
	if (operator == 3 && number2 == 0)
	{
		ft_putstr(STOPDIV);
		return ;
	}
	if (operator == 4 && number2 == 0)
	{
		ft_putstr(STOPMOD);
		return ;
	}
	else
		do_op(number1, operator, number2);
}

void	do_op(int number1, int operation, int number2)
{
	int (*function[5])(int, int);

	function[0] = &add;
	function[1] = &minus;
	function[2] = &multiply;
	function[3] = &divide;
	function[4] = &modulo;
	ft_putnbr(function[operation](number1, number2));
	write(1, "\n", 1);
}
