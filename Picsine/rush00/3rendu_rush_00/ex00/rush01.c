/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 14:57:30 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/07 15:44:45 by mgirardo         ###   ########.fr       */
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
			if (cy == 1 && cx == 1)
				ft_putchar('/');
			else if ((cy == y && cx == 1) || (cy == 1 && cx == x))
				ft_putchar('\\');
			else if (cy == y && cx == x)
				ft_putchar('/');
			else if ((cy > 1 && cy < y) && (cx > 1 && cx < x))
				ft_putchar(' ');
			else
				ft_putchar('*');
		}
		cx = 0;
		ft_putchar('\n');
	}
}
