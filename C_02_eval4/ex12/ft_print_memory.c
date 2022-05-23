/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njaros <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:54:59 by njaros            #+#    #+#             */
/*   Updated: 2021/09/07 17:37:11 by njaros           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_puthexa(int n)
{
	 int	i;
	char	hexa;

	if (n > 9)
	{
		i = 10;
		hexa = 'a';
		while (i < n)
		{
			hexa++;
			i++;
		}
		ft_putchar(hexa);
	}
	else
		ft_putchar(n + '0');
}

void	ft_conv_hexa (void *l)
{
	if (l / 16 != 0)
	{
		ft_conv_hexa(l / 16);
		ft_conv_hexa(l % 16);
	}
	if (l / 16 == 0)
		ft_puthexa(l % 16);
}

void	ft_conv_txt_hexa (char *str)
{
	unsigned char	*str2;

	str2 = (unsigned char *)str;
	while (*str2 != 0)
	{
		ft_conv_hexa(*str2);
		str2++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int	i;
	char *a;
	i = 0;
	while (i < size)
	{
		ft_conv_hexa(addr + i);
		write(1, ':', 1);
		a = *(addr + i);
		ft_conv_txt_hexa(a);
		write(1, "\n", 1);
		i++;
	}
}






int main ()
{
	void *a;
	char *str ="J'AIME LES FRUITS EN SIROP";
	a = str;
	ft_print_memory(a, 5);
	printf("%d\n", a);
	ft_conv_hexa(a);
	return 0;
}
