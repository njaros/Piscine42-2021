/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 09:08:43 by njaros            #+#    #+#             */
/*   Updated: 2021/09/15 14:01:44 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	a;
	int	*tab;

	a = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	tab = malloc(sizeof(*tab) * (max - min));
	while (min < max)
	{
		tab[a] = min;
		a++;
		min++;
	}
	*range = tab;
	return (a);
}

/*
{
	int	**wtf;
	wtf = malloc (10 * sizeof(int*));
	int	a = 2147483647;
	int	b = -9;
	int i = 0;
	int	c = ft_ultimate_range(wtf, a, b);
	
	//while(i < (b - a))
	//{
	printf("%d\n%d\n", c, wtf[0][i]);
	//i++;
	//}
	free (wtf);
}
*/