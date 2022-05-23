/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 08:35:11 by njaros            #+#    #+#             */
/*   Updated: 2021/09/15 09:05:37 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	j;
	int	*tab;

	if (max <= min)
		tab = NULL;
	else
	{
		tab = malloc ((max - min) * sizeof(int));
		if (!tab)
			return (0);
		j = min;
		i = 0;
		while (j < max)
		{
			tab[i] = j;
			j++;
			i++;
		}
	}
	return (tab);
}
/*
#include <stdio.h>
int main ()
{
	int i = 0;
	int min = 0;
	int max = 2;
	while (i < (max - min))
	{
		printf("%d ", ft_range(min, max)[i]);
		i++;
	}
}

*/