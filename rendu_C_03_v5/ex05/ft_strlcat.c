/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 18:10:11 by njaros            #+#    #+#             */
/*   Updated: 2021/09/14 08:54:07 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	k = i;
	while (src[j] != '\0')
		j++;
	if (k >= size)
		return (size + j);
	while ((i < size - 1) && (*src != '\0'))
	{
		dest[i] = *src;
		src++;
		i++;
	}
	dest[i] = '\0';
	return (k + j);
}
/*
#include <stdio.h>
#include <string.h>
int main ()
{
	char a[50] = "123456789";
	char b[] = "123";

	printf("%lu\n", strlcat(a, b, 1));
	printf("%s\n", a);
	char c[50] = "123456789";
	char d[] = "123";
	printf("%d\n", ft_strlcat(c, d, 1));
	printf("%s\n", c);
	return 0;
}*/
