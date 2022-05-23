/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:33:48 by njaros            #+#    #+#             */
/*   Updated: 2021/09/13 17:40:42 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_iterative_power(int nb, int power)
{
	int	michel;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	michel = 1;
	while (power-- > 0)
		michel = michel * nb;
	return (michel);
}
/*
int main ()
{
	printf("%d\n", ft_iterative_power(2, 6));
}*/
