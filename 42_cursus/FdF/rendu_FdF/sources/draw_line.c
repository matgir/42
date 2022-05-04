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

/*t_coord	set_sign(t_coord coo0, t_coord coo1)
{
	t_coord	sign;

	if (coo1.x_axe < coo0.x_axe)
		sign.x_axe = 1;
	else
		sign.x_axe = -1;
	if (coo1.y_axe < coo0.y_axe)
		sign.y_axe = 1;
	else
		sign.y_axe = -1;
	return (sign);
}

void	ft_to_trace(t_coord coo0, t_coord coo1, t_img *img)
{
	t_coord	diff;
	t_coord	end;
	t_coord	sign;
	int		err_marg[2];

	diff.x_axe = abs((int)coo1.x_axe - (int)coo0.x_axe);
	diff.y_axe = abs((int)coo1.y_axe - (int)coo0.y_axe);
	end = coo1;
	err_marg[0] = diff.x_axe - diff.y_axe;
	sign = set_sign(coo0, coo1);
	while (end.x_axe != coo0.x_axe || end.y_axe != coo0.y_axe)
	{
		my_mlx_pixel_put(img, end.x_axe, end.y_axe, 0x00FF00);
		err_marg[1] = err_marg[0] * 2;
		if (err_marg[1] > -diff.y_axe)
		{
			err_marg[0] -= diff.y_axe;
			end.x_axe += sign.x_axe;
		}
		if (err_marg[1] < diff.x_axe)
		{
			err_marg[0] += diff.x_axe;
			end.y_axe += sign.y_axe;
		}
	}
}*/

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
			my_mlx_pixel_put(img, x, y, 0x00FFFFFF);
			y++;
			p = p + 2 * dy - 2 * dx;
		}
		else
		{
			my_mlx_pixel_put(img, x, y, 0x00FFFFFF);
			p = p + 2 * dy;
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