/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 11:18:08 by chbadad           #+#    #+#             */
/*   Updated: 2021/02/21 11:35:56 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/do_op.h"

int	add(int a, int b)
{
	return (a + b);
}

int	minus(int a, int b)
{
	return (a - b);
}

int	multiply(int a, int b)
{
	return (a * b);
}

int	divide(int a, int b)
{
	return (a / b);
}

int	modulo(int a, int b)
{
	return (a % b);
}
