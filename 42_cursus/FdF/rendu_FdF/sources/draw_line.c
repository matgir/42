/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 17:51:46 by mgirardo          #+#    #+#             */
/*   Updated: 2022/05/02 17:51:48 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

void	ft_to_trace(t_coord coo0, t_coord coo1, t_img *img)
{
	float	dx;
	float	dy;
	float	p;
	float	x;
	float	y;

	dx = coo1.x_axe - coo0.x_axe;
	dy = coo1.y_axe - coo0.y_axe;
	x = coo0.x_axe;
	y = coo0.y_axe;
	p = 2 * (dy - dx);
	while (x < coo1.x_axe)
	{
		if (p >= 0)
		{
			my_mlx_pixel_put(img, x, y, 0x0000FF00);
			y++;
			p = p + (2 * dy) - (2 * dx);
		}
		else
		{
			my_mlx_pixel_put(img, x, y, 0x0000FF00);
			p = p + (2 * dy);
		}
		x++;
	}
}

void	draw_line(t_coord **coo, t_img *img, int x, int y)
{
	int	i;
	int	j;

	i = y;
	while(--i >= 0)
	{
		j = -1;
		while(++j < x)
		{
			if (j != x - 1)
				ft_to_trace(coo[i][j], coo[i][j + 1], img);
			if (i != 0)
				ft_to_trace(coo[i][j], coo[i - 1][j], img);
		}
	}
}