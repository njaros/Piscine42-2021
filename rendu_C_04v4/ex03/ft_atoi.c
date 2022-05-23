/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 07:38:52 by njaros            #+#    #+#             */
/*   Updated: 2021/09/13 13:45:01 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	white_space(char c)
{
	if ((c == '\t') || (c == '\n') || (c == '\v') || (c == '\f') || (c == ' '))
		return (1);
	return (0);
}

int	find_n(char *str)
{
	int	i;

	i = 0;
	while ((*str >= '0') && (*str <= '9'))
	{
		i = i + (*str - '0');
		str++;
		if ((*str >= '0') && (*str <= '9'))
		{
			i = 10 * i;
		}
	}
	return (i);
}

int	ft_atoi(char *str)
{
	int	sign;
	int	i;

	sign = 0;
	i = 0;
	while (white_space(*str))
	{
		str++;
	}
	while ((*str == '+') || (*str == '-'))
	{
		if (*str == '-')
			sign++;
		str++;
	}
	i = find_n(str);
	if ((sign % 2) == 1)
		i = -i;
	return (i);
}
/*#include <stdio.h>

int main ()
{
	char a[] = " \t\v\n\f   ---++---+649few3446";
	printf("%d\n", ft_atoi(a));
}*/
