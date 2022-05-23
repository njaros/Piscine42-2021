/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 12:18:50 by njaros            #+#    #+#             */
/*   Updated: 2021/09/09 11:51:49 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	if (size > 0)
	{
		while (*(src + i) != '\0')
		{
			if (i == size)
			{
				i--;
				break ;
			}
			*(dest + i) = *(src + i);
			i++;
		}
	}
	*(dest + i) = '\0';
	while (*(src + i) != '\0')
		i++;
	return (i);
}
