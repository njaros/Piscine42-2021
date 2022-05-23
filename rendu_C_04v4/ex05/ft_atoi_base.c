/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 13:06:46 by njaros            #+#    #+#             */
/*   Updated: 2021/09/15 07:20:11 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
		if ((base[j] == '-') || (base[j] == '+') || (base[j] == '\t')
			 || (base[j] == '\n') || (base[j] == '\v')
			 || (base[j] == '\f') || (base[j] == ' '))
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

int	num_pos(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	power(int i, int j)
{
	int	k;

	if (j == 0)
		return (1);
	k = i;
	while (j > 1)
	{
		k = k * i;
		j--;
	}
	return (k);
}

int	conversion(char *str, char *base)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = 0;
	while (base[i])
		i++;
	j = 0;
	while (num_pos(str[j], base) != -1)
	{
		j++;
	}
	k = 0;
	l = 0;
	while (l < j)
	{
		k = k + (num_pos(str[l], base) * power(i, (j - l - 1)));
		l++;
	}
	return (k);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;

	if (ok_base(base))
	{
		sign = 1;
		while ((*str == '\t') || (*str == '\n')
			|| (*str == '\v') || (*str == '\f')
			|| (*str == ' '))
		{
			str++;
		}
		while ((*str == '+') || (*str == '-'))
		{
			if (*str == '-')
				sign = -1 * sign;
			str++;
		}
		return (sign * (conversion(str, base)));
	}
	return (0);
}
/*
#include <stdio.h>
int	main()
{
	char a[] = "                 ---++-+---100101";
	char b[] = "0123456789abcdef";

	printf("%d\n", ft_atoi_base(a, b));
	return (0);
}*/
