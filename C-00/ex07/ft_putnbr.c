/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 10:36:40 by njaros            #+#    #+#             */
/*   Updated: 2021/09/03 12:16:47 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <math.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int	i;
	int	m;
	int	q;

	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	i = 0;
	m = n;
	while ((m / 10) != 0)
	{
		m = m / 10;
		i++;
	}
	while (i >= 0)
	{
		q = pow(10, i);
		ft_putchar((n / q) + '0');
		i--;
		n = n % q;
	}
}
