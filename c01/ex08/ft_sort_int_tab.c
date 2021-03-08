/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chbadad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 10:29:58 by chbadad           #+#    #+#             */
/*   Updated: 2021/02/03 13:17:25 by chbadad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int		ft_part(int arr[], int min_index, int max_index)
{
	int pivot;
	int i;
	int j;

	pivot = arr[max_index];
	i = min_index - 1;
	j = min_index;
	while (j <= max_index - 1)
	{
		if (arr[j] <= pivot)
		{
			i++;
			ft_swap(&arr[i], &arr[j]);
		}
		j++;
	}
	ft_swap(&arr[i + 1], &arr[max_index]);
	return (i + 1);
}

void	ft_sort(int tab[], int min_index, int max_index)
{
	int pivot;

	if (min_index < max_index)
	{
		pivot = ft_part(tab, min_index, max_index);
		ft_sort(tab, min_index, pivot - 1);
		ft_sort(tab, pivot + 1, max_index);
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	ft_sort(tab, 0, size - 1);
}
