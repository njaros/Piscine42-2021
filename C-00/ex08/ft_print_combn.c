/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 12:18:34 by njaros            #+#    #+#             */
/*   Updated: 2021/09/04 08:03:26 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

void	print_digits(int *digits, int size)
{
	int		i;
	char	to_print;

	if (size == 0)
		return ;
	i = 0;
	while (i < size)
	{
		to_print = digits[i] + '0';
		write(1, &to_print, 1);
		++i;
	}
	write(1, "\n", 1);
}

void	recu(int n, int i, int depth, int *digits)
{
	if (depth == n)
		return (print_digits(digits, n));
	if (10 - i < n - depth)
		return ;
	while (i <= 9)
	{
		digits[depth] = i;
		++i;
		recu(n, i, depth + 1, digits);
	}
}

void	ft_print_combn(int n)
{
	int	digits[10];

	recu(n, 0, 0, digits);
	write(1, "\n", 1);
}

int	main(int ac, char **av)
{
	int	nb;

	if (ac != 2)
	{
		write(1, "need a digit as parameter\n", 26);
		return (1);
	}
	nb = av[1][0] - '0';
	if (ft_strlen(av[1]) > 1 || nb < 0 || nb > 9)
	{
		write(1, "enter a digit plz\n", 18);
		return (1);
	}
	ft_print_combn(nb);
	return (0);
}
