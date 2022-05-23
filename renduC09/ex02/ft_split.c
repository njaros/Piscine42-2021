/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 17:44:28 by njaros            #+#    #+#             */
/*   Updated: 2021/09/20 17:44:30 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_char_is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_nb_string(char *str, char *charset)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		while (ft_char_is_charset(str[i], charset) && str[i])
			i++;
		if (str[i])
			k++;
		while (!ft_char_is_charset(str[i], charset) && str[i])
			i++;
	}
	return (k);
}

int	ft_size_str(char *str, char *charset, int i)
{
	int	j;
	int	k;

	k = 0;
	while (str[i])
	{
		j = 0;
		while (charset[j])
		{
			if (charset[j] == str[i])
				return (k);
			j++;
		}
		i++;
		k++;
	}
	return (i);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		k;
	char	**strs;

	i = 0;
	j = 0;
	strs = malloc(sizeof(*strs) * (ft_nb_string(str, charset) + 1));
	if (!strs)
		return (0);
	while (j < ft_nb_string(str, charset))
	{
		while (ft_char_is_charset(str[i], charset) && str[i])
			i++;
		strs[j] = malloc(sizeof(**strs) * (ft_size_str(str, charset, i) + 1));
		if (!strs[j])
			return (0);
		k = 0;
		while (ft_size_str(str, charset, i) && str[i])
			strs[j][k++] = str[i++];
		strs[j][k] = '\0';
		j++;
	}
	strs[j] = 0;
	return (strs);
}
/*
#include <stdio.h>
int main (int argc, char **argv)
{
	int mes_fesses = 0;
	(void)argc;
	if (argc < 3)
	return (mes_fesses);
	int i = 0;
	char **a;
	a = ft_split(argv[1], argv[2]);
	while (a[i])
	{
		printf("%s\n", a[i]);
		i++;
	}
}
*/