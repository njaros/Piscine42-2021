/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 07:31:51 by njaros            #+#    #+#             */
/*   Updated: 2021/09/15 07:36:26 by njaros           ###   ########lyon.fr   */
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

int	main(int argc, char **argv)
{
	int	i;

	i = (argc - 1);
	while (i >= 1)
	{
		ft_putstr(argv[i]);
		write (1, "\n", 1);
		i--;
	}
}
