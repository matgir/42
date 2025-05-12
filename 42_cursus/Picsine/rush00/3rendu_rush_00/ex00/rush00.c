/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 15:23:24 by maroly            #+#    #+#             */
/*   Updated: 2021/08/08 18:13:14 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			if ((cy == 1 || cy == y) && (cx == 1 || cx == x))
				ft_putchar('o');
			else if ((cx == 1 || cx == x) && (cy > 1 && cy < y))
				ft_putchar('|');
			else if ((cy > 1 && cy < y) && (cx > 1 && cx < x))
				ft_putchar(' ');
			else
				ft_putchar('-');
		}
		cx = 0;
		ft_putchar('\n');
	}
}
