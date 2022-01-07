/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 10:48:31 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/09 10:31:21 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int i)
{
	write(1, &i, 1);
}

void	ft_print(int G, int D)
{	
	ft_putchar(G / 10 + '0');
	ft_putchar(G % 10 + '0');
	ft_putchar(' ');
	ft_putchar(D / 10 + '0');
	ft_putchar(D % 10 + '0');
	if (!(G == 98))
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	int	G;
	int	D;

	G = 0;
	while (G < 99)
	{
		D = G + 1;
		while (D < 100)
		{
			ft_putchar(G / 10 + '0');
			ft_putchar(G % 10 + '0');
			ft_putchar(' ');
			ft_putchar(D / 10 + '0');
			ft_putchar(D % 10 + '0');
			if (!(G == 98))
			{
				write(1, ", ", 2);
			}
			D++;
		}
		G++;
	}
}
