/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 07:38:50 by njaros            #+#    #+#             */
/*   Updated: 2021/09/17 13:40:39 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	write(1, c, i);
}

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

void	ft_swap(char **a, char **b)
{
	char	*memoire;

	memoire = *a;
	*a = *b;
	*b = memoire;
}

void	ft_sort_char_tab(char **tab, int size)
{
	char	*temp;
	int		pos_min;
	int		i;
	int		j;

	i = 1;
	while (i < (size - 1))
	{
		temp = tab[i];
		pos_min = i;
		j = i + 1;
		while (j < size)
		{
			if (ft_strcmp(tab[j], temp) < 0)
			{
				temp = tab[j];
				pos_min = j;
			}
			j++;
		}
		ft_swap(&tab[pos_min], &tab[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	ft_sort_char_tab(argv, argc);
	while (argv[i])
	{
		ft_putstr(argv[i]);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
