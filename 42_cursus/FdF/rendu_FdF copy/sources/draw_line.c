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
}

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
}*/

t_coord	set_sign(t_coord coo0, t_coord coo1)
{
	t_coord	sign;

	if (coo0.x_axe < coo1.x_axe)
		sign.x_axe = 1;
	else
		sign.x_axe = -1;
	if (coo0.y_axe < coo1.y_axe)
		sign.y_axe = 1;
	else
		sign.y_axe = -1;
	return (sign);
}

void	ft_to_trace(t_mlx *mlx, t_coord coo0, t_coord coo1, t_img *img)
{
	t_coord	delta;
	t_coord	sign;
	int		error[2];

	delta.x_axe = abs(coo1.x_axe - coo0.x_axe);
	delta.y_axe = abs(coo1.y_axe - coo0.y_axe);
	sign = set_sign(coo0, coo1);
	
	//printf("Print from %g;%g to %g;%g\n", coo0.x_axe, coo0.y_axe, coo1.x_axe, coo1.y_axe);
	if (delta.x_axe > delta.y_axe)
		error[0] = delta.x_axe/2;
	else
		error[0] = -delta.y_axe/2;

	int x_sup = coo0.x_axe > coo1.x_axe;
	int y_sup = coo0.y_axe > coo1.y_axe;
	while (1)
	{
		if ((coo0.x_axe >= 1 && coo0.x_axe <= 1920) && (coo0.y_axe >= 1 && coo0.y_axe <= 960))
			my_mlx_pixel_put(img, coo0.x_axe, coo0.y_axe, 0x00FF00);
		//printf("%g >= %g && %g >= %g\n", coo0.x_axe ,coo1.x_axe , coo0.y_axe , coo1.y_axe);
		if ((x_sup && coo0.x_axe <= coo1.x_axe) || (!x_sup && coo0.x_axe >= coo1.x_axe))
		{
			if ((y_sup && coo0.y_axe <= coo1.y_axe) || (!y_sup && coo0.y_axe >= coo1.y_axe))
			{
				break;
			}
		}
		//if (coo0.x_axe >= coo1.x_axe && coo0.y_axe >= coo1.y_axe)
		//	break;
		error[1] = error[0];
		if (error[1] > -delta.x_axe)
		{
			error[0] -= delta.y_axe;
			coo0.x_axe += sign.x_axe;
		}
		if (error[1] < delta.y_axe)
		{
			error[0] += delta.x_axe;
			coo0.y_axe += sign.y_axe;
		}
		//mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img->img, 0, 0);
	}
	//printf("----------------\n");
}

void	draw_line(t_mlx *mlx, t_coord **coo, t_img *img, int x, int y)
{
	int	i;
	int	j;

	i = y;
	while(--i >= 0)
	{
		j = -1;
		while(++j < x)
		{
			if (i != 0)
				ft_to_trace(mlx, coo[i][j], coo[i - 1][j], img);
			if (j != x - 1)
				ft_to_trace(mlx, coo[i][j], coo[i][j + 1], img);
		}
	}
}