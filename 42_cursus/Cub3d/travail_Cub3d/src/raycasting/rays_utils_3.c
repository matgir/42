/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_utils_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:52:44 by mgirardo          #+#    #+#             */
/*   Updated: 2024/01/17 16:52:45 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/* following the calculus started in rays_utils_2.c */
float	distance_calculus(float p_x, float p_y, float hit_x, float hit_y)
{
	return (sqrt((hit_x - p_x) * (hit_x - p_x)
			+ (hit_y - p_y) * (hit_y - p_y)));
}

void	set_distance(t_vars *cub, t_cast *cast)
{
	if (cast->horizontal_hit)
		cast->horizontal_hit_distance = distance_calculus(cub->player.x,
				cub->player.y, cast->horizontal_hit_x, cast->horizontal_hit_y);
	else
		cast->horizontal_hit_distance = (float)2147483647;
	if (cast->vertical_hit)
		cast->vertical_hit_distance = distance_calculus(cub->player.x,
				cub->player.y, cast->vertical_hit_x, cast->vertical_hit_y);
	else
		cast->vertical_hit_distance = (float)2147483647;
}

void	compare_distance(t_cast *cast, t_ray *ray, float ray_angle)
{
	if (cast->vertical_hit_distance < cast->horizontal_hit_distance)
	{
		ray->distance = cast->vertical_hit_distance;
		ray->wall_hit_x = cast->vertical_hit_x;
		ray->wall_hit_y = cast->vertical_hit_y;
		ray->wall_hitcontent = cast->vertical_content;
		ray->was_hitvertical = 1;
	}
	else
	{
		ray->distance = cast->horizontal_hit_distance;
		ray->wall_hit_x = cast->horizontal_hit_x;
		ray->wall_hit_y = cast->horizontal_hit_y;
		ray->was_hitvertical = 0;
		ray->wall_hitcontent = cast->horizontal_content;
	}
	ray->ray_angle = ray_angle;
	ray->ray_facingdown = cast->ray_facingdown;
	ray->ray_facingup = cast->ray_facingup;
	ray->ray_facingleft = cast->ray_facingleft;
	ray->ray_facingright = cast->ray_facingright;
}

void	adjust_distance(t_player *player, t_ray *ray)
{
	ray->minimap_dist = ray->distance;
	ray->distance *= cos(ray->ray_angle - player->rotationangle);
}
