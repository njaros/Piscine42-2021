/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 18:21:10 by njaros            #+#    #+#             */
/*   Updated: 2021/09/13 13:05:07 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned char	*c1;
	unsigned char	*c2;
	 unsigned int	i;

	if (n == 0)
		return (0);
	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	i = 0;
	while ((i + 1 < n) && (*c1 != '\0'))
	{
		if (*c1 > *c2)
			return (*c1 - *c2);
		if (*c1 < *c2)
			return (*c1 - *c2);
		c1++;
		c2++;
		i++;
	}
	return (*c1 - *c2);
}
/*
#include <string.h>
#include <stdio.h>
int main ()
{
	char	a[] = "mon q est beau";
	char	b[] = "mon c est beau";

	printf("%d\n", ft_strncmp(a, b, 78));
	printf("%d\n", strncmp(a, b, 78));
	return (0);
}*/
