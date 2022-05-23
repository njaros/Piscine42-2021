/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:50:00 by njaros            #+#    #+#             */
/*   Updated: 2021/09/15 07:13:40 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	lg_base(char *b)
{
	int	i;

	i = 0;
	while (b[i])
		i++;
	return (i);
}

int	ok_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i])
		i++;
	if (i <= 1)
		return (0);
	while (base[j])
	{
		if ((base[j] == '-') || (base[j] == '+'))
			return (0);
		i = j + 1;
		while (base[i])
		{
			if (base[i] == base[j])
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

void	transform(unsigned int nb, char *base)
{
	if (nb / lg_base(base) > 0)
	{
		transform(nb / lg_base(base), base);
		transform(nb % lg_base(base), base);
	}
	if (nb / lg_base(base) == 0)
		write(1, &base[nb], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	n;

	if (ok_base(base))
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			n = -nbr;
		}
		else
			n = nbr;
		transform(n, base);
	}
}
/*
int main ()
{
	char	a[] = "0123456789ab1f";
	ft_putnbr_base(-2147483648, a);
	return (0);
}*/
