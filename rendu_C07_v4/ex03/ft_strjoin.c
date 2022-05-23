/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 14:03:31 by njaros            #+#    #+#             */
/*   Updated: 2021/09/16 13:56:09 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return (count);
}

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

int	ft_count_size(char **adr, int size)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (size > 0)
	{
		while (adr[size - 1][i])
		{
			count++;
			i++;
		}
		i = 0;
		size--;
	}
	return (count);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*joined;
	int		i;
	int		j;

	j = 0;
	i = ft_count_size(strs, size);
	joined = malloc ((i + ((ft_strlen(sep)) * size) * sizeof(char)) + 1);
	if (!(joined))
		return (NULL);
	if (size == 0)
		return (joined);
	joined[0] = '\0';
	while (j < (size - 1))
	{
		ft_strcat(joined, strs[j]);
		ft_strcat(joined, sep);
		j++;
	}
	ft_strcat(joined, strs[j]);
	return (joined);
}
/*
#include <stdio.h>
int main (int argc, char **argv)
{
	char sep[] = "www";
	{
		argv++;
		printf("%s\n", ft_strjoin(argc -1, argv, sep));
	}
	return (0);
}
*/