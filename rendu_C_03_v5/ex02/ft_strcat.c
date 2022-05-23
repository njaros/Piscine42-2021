/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 11:03:59 by njaros            #+#    #+#             */
/*   Updated: 2021/09/13 13:17:25 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	i;

	i = 0;
	while (dest[i] != '\0')
		i++;
	while (*src != '\0')
	{
		dest[i] = *src;
		src++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char a[50] = "j'aime les fruits";
	char b[] = "en sirop";
	char c[50] = "j'aime les fruits";
	char d[] = "en sirop";
	printf("%s\n%s\n", strcat(a, b), a);
	printf("%s\n%s\n", ft_strcat(c, d), c);
	return (0);
}*/
