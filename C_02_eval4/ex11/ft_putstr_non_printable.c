/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 13:43:36 by njaros            #+#    #+#             */
/*   Updated: 2021/09/08 10:39:36 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(unsigned char c)
{
	write(1, &c, 1);
}

void	hexa(int n)
{
	 int	i;
	char	hexa;

	if (n > 9)
	{
		i = 10;
		hexa = 'a';
		while (i < n)
		{
			hexa++;
			i++;
		}
		ft_putchar(hexa);
	}
	else
		ft_putchar(n + '0');
}

void	ft_puthexa(unsigned char c)
{
	int	diz;
	int	unit;

	ft_putchar(92);
	diz = c / 16;
	hexa(diz);
	unit = c % 16;
	hexa(unit);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned char	*str2;

	str2 = (unsigned char *)str;
	while (*str2 != '\0')
	{
		if ((*str2 >= 32) && (*str2 < 127))
			ft_putchar(*str2);
		else
			ft_puthexa(*str2);
		str2++;
	}
}
