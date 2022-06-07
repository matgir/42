/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_trace_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:36:31 by mgirardo          #+#    #+#             */
/*   Updated: 2022/06/07 17:36:33 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

void	project_iso(int *x, int *y, int z)
{
	int	x_tmp;
	int	y_tmp;

	(void)z;
	x_tmp = *x;
	y_tmp = *y;
	*x = (x_tmp - y_tmp) * cos(0.55);
	*y = -z + (x_tmp + y_tmp) * sin(0.55);
}

t_point	project(t_iso point, t_coord *coord)
{
	t_point	displayed_point;

	displayed_point.r_point = point;
	point.x *= coord->camera.zoom;
	point.y *= coord->camera.zoom;
	point.z *= coord->camera.zoom / coord->camera.z_scale;
	point.x -= (coord->column_count * coord->camera.zoom) / 2;
	point.y -= (coord->line_count * coord->camera.zoom) / 2;
	project_iso(&point.x, &point.y, point.z);
	point.x += WHIDTH / 2 + coord->camera.x_offset;
	point.y += (HEIGHT + coord->camera.zoom) / 2
		+ coord->camera.y_offset;
	displayed_point.x = point.x;
	displayed_point.y = point.y;
	return (displayed_point);
}

t_point	set_sign(t_point p1, t_point p2)
{
	t_point	sign;

	if (p2.x < p1.x)
		sign.x = 1;
	else
		sign.x = -1;
	if (p2.y < p1.y)
		sign.y = 1;
	else
		sign.y = -1;
	return (sign);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	trace_line(t_point p1, t_point p2, t_img *img)
{
	t_point	delta;
	t_point	sign;
	t_point	cur;
	int		error[2];

	delta.x = abs(p1.x - p2.x);
	delta.y = abs(p1.y - p2.y);
	sign = set_sign(p1, p2);
	error[0] = delta.x - delta.y;
	cur = p2;
	while (cur.x != p1.x || cur.y != p1.y)
	{
		if ((cur.x >= 1 && cur.x < 1920) && (cur.y >= 1 && cur.y < 960))
			my_mlx_pixel_put(img, cur.x, cur.y, 0x00FF00);
		error[1] = error[0] * 2;
		if (error[1] > -delta.y)
		{
			error[0] -= delta.y;
			cur.x += sign.x;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			cur.y += sign.y;
		}
	}
}