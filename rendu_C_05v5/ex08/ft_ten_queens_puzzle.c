/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:47:48 by njaros            #+#    #+#             */
/*   Updated: 2021/09/15 09:19:46 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	test_cond(char *c, int nb_q, int i)
{
	int	j;
	int	k;

	k = i + '0';
	if (nb_q == 0)
		return (1);
	j = nb_q - 1;
	while (j >= 0)
	{
		if (c[j] == k)
			return (0);
		if ((((k - c[j]) == (j - nb_q))) || (((k - c[j]) == (nb_q - j))))
			return (0);
		j--;
	}
	return (1);
}

void	put_q(char *c, int nb_q, int here)
{
	c[nb_q] = here + '0';
}

int	recu(char *pos, int nb_q, int *count)
{
	int	i;

	i = 0;
	if (nb_q == 10)
	{
		write (1, pos, 10);
		write (1, "\n", 1);
		*count = *count + 1;
		return (1);
	}	
	while (i < 10)
	{
		if (test_cond(pos, nb_q, i))
		{
			put_q(pos, nb_q, i);
			recu(pos, nb_q + 1, count);
		}
		i++;
	}
	return (*count);
}

int	ft_ten_queens_puzzle(void)
{
	char	pos[10];
	int		count[1];

	*count = 0;
	return (recu(pos, 0, count));
}
/*
#include <stdio.h>
int main ()
{
	printf("%d\n", ft_ten_queens_puzzle());
	return (0);
}*/
