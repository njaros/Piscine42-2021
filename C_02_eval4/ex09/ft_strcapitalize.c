/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 10:50:19 by njaros            #+#    #+#             */
/*   Updated: 2021/09/08 12:33:33 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	alpha(char c)
{
	if (((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')))
		return (1);
	return (0);
}

int	num(char c)
{
	if ((c >= '0') && (c <= '9'))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	unsigned int	i;

	i = 0;
	if (str[i] == '\0')
		return (str);
	if ((str[i] >= 'a') && (str[i] <= 'z'))
		str[i] = str[i] + ('A' - 'a');
	i++;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'a') && (str[i] <= 'z'))
			if (!((alpha(str[i - 1])) || (num(str[i - 1]))))
				str[i] = str[i] + ('A' - 'a');
		if ((str[i] >= 'A') && (str[i] <= 'Z'))
			if ((alpha(str[i - 1])) || (num(str[i - 1])))
				str[i] = str[i] - ('A' - 'a');
		i++;
	}
	return (str);
}
