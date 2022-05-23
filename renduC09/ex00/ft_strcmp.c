/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 18:07:32 by njaros            #+#    #+#             */
/*   Updated: 2021/09/13 13:00:28 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	while (*c1 != '\0')
	{
		if (*c1 > *c2)
			return (*c1 - *c2);
		if (*c1 < *c2)
			return (*c1 - *c2);
		c1++;
		c2++;
	}
	return (*c1 - *c2);
}
/*
#include <string.h>
#include <stdio.h>
int main ()
{
	char a[] = "";
	char b[] = "";

	printf("%d\n", strcmp(a, b));
	printf("%d\n", ft_strcmp(a, b));
	int main ();
}*/
