/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboidin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 14:53:24 by gboidin           #+#    #+#             */
/*   Updated: 2021/08/07 15:43:52 by gboidin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	cx;
	int	cy;

	cx = 0;
	cy = 0;
	if (x < 1 || y < 1)
		return ;
	while (++cy <= y)
	{
		while (++cx <= x)
		{
			if (cx == 1 && (cy == 1 || cy == y))
				ft_putchar('A');
			else if (cx == x && (cy == 1 || cy == y))
				ft_putchar('C');
			else if ((cy > 1 && cy < y)
				&& (cx > 1 && cx < x))
				ft_putchar(' ');
			else
				ft_putchar('B');
		}
		cx = 0;
		ft_putchar('\n');
	}
}
