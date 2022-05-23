/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 14:04:29 by njaros            #+#    #+#             */
/*   Updated: 2021/09/20 14:04:34 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

void	ft_show_tab(struct s_stock_str *par);

char	*ft_strdup(char *src)
{
	int		i;
	char	*copy;

	i = 0;
	while (src[i])
		i++;
	copy = malloc (i * sizeof(char) + 1);
	if (!copy)
		return (0);
	i = 0;
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

int	ft_l(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*pokedex;
	int					i;

	i = 0;
	pokedex = malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (!pokedex)
		return (NULL);
	while (i < ac)
	{
		pokedex[i].size = ft_l(av[i]);
		pokedex[i].str = av[i];
		pokedex[i].copy = ft_strdup(av[i]);
		i++;
	}
	pokedex[i].str = 0;
	return (pokedex);
}
/*
int main (int argc, char **argv)
{
	struct s_stock_str *a;
	a = ft_strs_to_tab(argc, argv);
	ft_show_tab(a);
	//je free pas, la flemme
}
*/