/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ruch00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 21:50:13 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/06 23:11:10 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	fr_putchar(char c);

void	rush(int x, int y)
{
	int count_x;
	int count_y;

	count_x = 1;
	count_y = 1;

	while count_x <= x
	{
		while count_y <= y
		{
			if ((count_y = y - count_y, count_x = x - (x - 1)) && (count_y = y (y - 1), count_x = x))
			{
				ft_putchar(A);
			}











			if ((count_y = y - (y - 1), count_x = x - (x - 1)) && (count_y = y (y - 1), count_x = x))
			
			if ((count_y = y - (y - 1), count_x = x - (y - 1)) && (count_y = y (y - 1), count_x = x))
			if ((count_y = y - (y - 1), count_x = x - (y - 1)) && (count_y = y (y - 1), count_x = x))
			if ((count_y = y - (y - 1), count_x = x - (y - 1)) && (count_y = y (y - 1), count_x = x))
			if ((count_y = y - (y - 1), count_x = x - (y - 1)) && (count_y = y (y - 1), count_x = x))
			if ((count_y = y - (y - 1), count_x = x - (y - 1)) && (count_y = y (y - 1), count_x = x))
			if ((count_y = y - (y - 1), count_x = x - (y - 1)) && (count_y = y (y - 1), count_x = x))
		}
	}
}
