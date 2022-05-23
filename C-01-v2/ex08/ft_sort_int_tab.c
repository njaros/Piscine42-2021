/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 15:04:19 by njaros            #+#    #+#             */
/*   Updated: 2021/09/05 15:43:03 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int	memoire;

	memoire = *a;
	*a = *b;
	*b = memoire;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	temp;
	int	pos_min;
	int	i;
	int	j;

	i = 0;
	while (i < (size - 1))
	{
		temp = tab[i];
		pos_min = i;
		j = i + 1;
		while (j < size)
		{
			if (tab[j] < temp)
			{
				temp = tab[j];
				pos_min = j;
			}
			j++;
		}
		ft_swap(&tab[pos_min], &tab[i]);
		i++;
	}
}
