/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 12:18:34 by njaros            #+#    #+#             */
/*   Updated: 2021/09/04 08:03:26 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <math.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_combn(int n)
{
	int a[n];
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	a[i] = 0;
	for (a[i] = 0, a[i]++ , (10 - (n - i)))
	{
		a[(i + 1)] = a[i] + 1;
:q




		for (j = 0, j++, (n-1))
		{
			ft_putchar(a[j]);
		}
	}

			
			


}
