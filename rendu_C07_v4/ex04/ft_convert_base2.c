/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:17:18 by njaros            #+#    #+#             */
/*   Updated: 2021/09/16 16:08:16 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int				ok_base(char *base);
int				num_pos(char c, char *base);
int				power(int i, int j);
unsigned int	conversion(char *str, char *base);
unsigned int	ft_atoi_base(char *str, char *base);

int	lg_base(char *b)
{
	int	i;

	i = 0;
	while (b[i])
		i++;
	return (i);
}

void	transform(unsigned int nb, char *base, char *nbr_based, int *indice)
{
	if (nb / lg_base(base) > 0)
	{
		transform(nb / lg_base(base), base, nbr_based, indice);
		transform(nb % lg_base(base), base, nbr_based, indice);
	}
	if (nb / lg_base(base) == 0)
	{
		nbr_based[*indice] = base[nb];
		nbr_based++;
		*indice = *indice + 1;
	}
}

int	lg(int nbr, char *base)
{
	int	i;

	i = 0;
	while ((nbr / lg_base(base)) > 0)
	{
		i++;
		nbr = nbr / lg_base(base);
	}
	if (nbr < 0)
		return (i + 2);
	else
		return (i + 1);
}

char	*ft_putnbr_base(int nbr, char *base)
{
	char			*nbr_based;
	unsigned int	n;
	int				i[1];

	*i = 0;
	nbr_based = malloc(sizeof(char) * lg(nbr, base) + 1);
	if (nbr < 0)
	{
		*i = 1;
		nbr_based[0] = '-';
		n = -nbr;
		transform(n, base, nbr_based, i);
	}
	else
	{
		n = nbr;
		transform(n, base, nbr_based, i);
	}
	nbr_based[*i] = '\0';
	return (nbr_based);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	if (!(ok_base(base_from)) || !(ok_base(base_to)))
		return (NULL);
	return (ft_putnbr_base(ft_atoi_base(nbr, base_from), base_to));
}

/*
#include <stdio.h>
int main (int argc, char **argv)
{
	(void)argc;
	printf("%s\n", ft_convert_base(argv[1], argv[2], argv[3]));
	return (0);
}
*/