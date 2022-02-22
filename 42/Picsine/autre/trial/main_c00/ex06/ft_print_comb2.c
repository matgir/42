/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 10:48:31 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/08 15:24:10 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int i)
{
	write(1, &i, 1);
}

void	ft_print(int G, int D)
{
	if (G / 10 + '0' <= D / 10 + '0' && G % 10 + '0' < D % 10 + '0')
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
}

void	ft_print_comb2(void)
{
	int	G;
	int	D;

	G = 0;
	D = 1;
	while (!(G == D))
	{
		D = G + 1;
		while (D < 100)
		{
			ft_print(G, D);
			D++;
		}
		G++;
	}
}
