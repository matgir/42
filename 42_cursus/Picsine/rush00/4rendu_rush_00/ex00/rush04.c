/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 15:34:27 by maroly            #+#    #+#             */
/*   Updated: 2021/08/07 15:47:06 by maroly           ###   ########.fr       */
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
			if (cx == 1 && cy == 1)
				ft_putchar('A');
			else if ((cx == 1 && cy == y) || (cx == x && cy == 1))
				ft_putchar('C');
			else if (cx == x && cy == y)
				ft_putchar('A');
			else if ((cy > 1 && cy < y) && (cx > 1 && cx < x))
				ft_putchar(' ');
			else
				ft_putchar('B');
		}
		cx = 0;
		ft_putchar('\n');
	}
}
