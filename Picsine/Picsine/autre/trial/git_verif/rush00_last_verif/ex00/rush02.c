/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 21:41:11 by maroly            #+#    #+#             */
/*   Updated: 2021/08/06 23:54:29 by maroly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	count_x;
	int	count_y;

	count_x = 0;
	count_y = 0;
	if (x < 1 || y < 1)
		return ;
	while (++count_y <= y)
	{
		while (++count_x <= x)
		{
			if (count_y == 1 && (count_x == 1 || count_x == x))
				ft_putchar('A');
			else if (count_y == y && (count_x == 1 || count_x == x))
				ft_putchar('C');
			else if ((count_y > 1 && count_y < y)
				&& (count_x > 1 && count_x < x))
				ft_putchar(' ');
			else
				ft_putchar('B');
		}
		count_x = 0;
		ft_putchar('\n');
	}
}
