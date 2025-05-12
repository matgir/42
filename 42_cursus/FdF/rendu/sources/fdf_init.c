/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:37:53 by mgirardo          #+#    #+#             */
/*   Updated: 2022/06/07 17:37:55 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

int	def_min(int w, int h)
{
	if (w < h)
		return (w);
	return (h);
}

t_coord	setup_camera(t_coord coord)
{
	coord.camera.zoom = def_min((WHIDTH - 384) / coord.column_count,
			(HEIGHT - 192) / coord.line_count);
	coord.camera.z_scale = 10;
	coord.camera.x_offset = 0;
	coord.camera.y_offset = 0;
	return (coord);
}

t_coord	init_map(t_coord coord)
{
	int	i;
	int	j;

	coord.z_max = coord.coord[0][0];
	coord.z_min = coord.coord[0][0];
	i = -1;
	while (++i < coord.line_count)
	{
		j = -1;
		while (++j < coord.column_count)
		{
			if (coord.coord[i][j] > coord.z_max)
				coord.z_max = coord.coord[i][j];
			if (coord.coord[i][j] < coord.z_min)
				coord.z_min = coord.coord[i][j];
		}
	}
	coord.z_range = coord.z_max - coord.z_min;
	return (setup_camera(coord));
}

t_iso	init_iso(int x, int y, int z)
{
	t_iso	iso_point;

	iso_point.x = x;
	iso_point.y = y;
	iso_point.z = z;
	return (iso_point);
}

void	trace_line(t_point p1, t_point p2, t_img *img)
{
	t_point	delta;
	t_point	cur;

	delta.x = abs(p1.x - p2.x);
	delta.y = abs(p1.y - p2.y);
	cur = p2;
	fill_img(delta, cur, p1, img);
}
