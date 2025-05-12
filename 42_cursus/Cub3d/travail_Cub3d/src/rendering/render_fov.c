/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <itahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 21:15:27 by mgirardo          #+#    #+#             */
/*   Updated: 2024/01/17 15:49:20 by itahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	dda_utils(t_vars *var, t_ray *ray, int color, int *i)
{
	int	x;
	int	y;

	x = ray->line.current_x;
	y = ray->line.current_y;
	my_mlx_pixel_put(var, x, y, color);
	ray->line.current_x += ray->line.xinc;
	ray->line.current_y += ray->line.yinc;
	*i += 1;
}

void	dda(t_player *player, t_vars *var, t_ray *ray, int color)
{
	int	i;

	i = 0;
	ray->line.delta_x = ray->wall_hit_x - player->x;
	ray->line.delta_y = ray->wall_hit_y - player->y;
	if (abs(ray->line.delta_x) >= abs(ray->line.delta_y))
		ray->line.sidelength = abs(ray->line.delta_x);
	else
		ray->line.sidelength = abs(ray->line.delta_y);
	ray->line.xinc = ray->line.delta_x / (float)ray->line.sidelength;
	ray->line.yinc = ray->line.delta_y / (float)ray->line.sidelength;
	ray->line.current_x = player->x;
	ray->line.current_y = player->y;
	while (i < ray->line.sidelength)
	{
		while (i < ray->line.sidelength)
			dda_utils(var, ray, color, &i);
	}
}

void	render_fov(t_vars *var, t_player *player, int color)
{
	int	i;

	i = 0;
	while (i < (WINDOW_WIDTH / WALL_STRIP_WIDTH))
	{
		dda(player, var, &var->rays[i], color);
		i++;
	}
}
