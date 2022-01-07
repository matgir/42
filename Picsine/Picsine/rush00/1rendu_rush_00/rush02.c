/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maroly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 21:41:11 by maroly            #+#    #+#             */
/*   Updated: 2021/08/06 23:31:36 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_putchar(char c);

void print_s(int count_x, int count_y, int x, int y)
{
	while (count_x <= x)
	{
	if ((count_y == 1) && (count_x == 1 || count_x == x))
	{
				ft_putchar('A');
				else
				ft_putchar('B');
	}
	else if (count_y == y)
	{
		{
			if(count_x == 1 || count_x == x)
				ft_putchar('C');
			else
				ft_putchar('B');
		}
	}
	else 
	{
		{
			if(count_x == 1 || count_x == x)
				ft_putchar('B');
			else
				ft_putchar(' ');
		}
	}
	count_x++;
	}
}

void rush (int x, int y)
{
	int count_x;
	int count_y;

	count_x = 1;
	count_y= 1;

	if (x < 1 || y < 1)
		return ;

	while (count_y <= y)
	{
		print_s(count_x, count_y, x, y);
		count_y++;
		count_x = 1;
		ft_putchar('\n');
	}
}
