/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 11:16:25 by njaros            #+#    #+#             */
/*   Updated: 2021/09/14 08:49:25 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while ((j < nb) && (*src != '\0'))
	{
		dest[i] = *src;
		j++;
		i++;
		src++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>
int main ()
{
	char a[50] = "les cerises";
	char b[] = "woif893hlscn0gffsjaj75yv";
	char c[50] = "les cerises";
	char d[] = "woif893hlscn0gffsjaj75yv";
	printf("%s\n%s\n", strncat(a, b, 5), ft_strncat(c, d, 5));
	return (0);
}
*/
