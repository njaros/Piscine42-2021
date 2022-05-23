/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 11:29:22 by njaros            #+#    #+#             */
/*   Updated: 2021/09/13 13:31:53 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

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

unsigned int	ft_l(char *str)
{
	int	i;

	i = 0;
	while (*str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	if (to_find[0] == '\0')
		return (str);
	while (((ft_strncmp(str, to_find, ft_l(to_find))) != 0) && (*str != '\0'))
	{
		str++;
	}
	if (*str == '\0')
		return (0);
	return (str);
}
/*
#include <string.h>
#include <stdio.h>
int main ()
{
	char a[] = "le petit train kipu ne va pas vite";
	char b[] = "rapide";
	printf("%s\n%s\n", strstr(a, b), ft_strstr(a, b));
	return (0);
}
*/
