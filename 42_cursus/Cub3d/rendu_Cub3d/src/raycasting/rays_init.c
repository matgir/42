/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:12:25 by mgirardo          #+#    #+#             */
/*   Updated: 2024/01/15 15:12:29 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	init_rays(t_vars *cub)
{
	int	ray_id;

	ray_id = 0;
	while (ray_id < (WINDOW_WIDTH / WALL_STRIP_WIDTH))
	{
		cub->rays[ray_id].ray_facingdown = 0;
		cub->rays[ray_id].ray_facingup = 0;
		cub->rays[ray_id].ray_facingleft = 0;
		cub->rays[ray_id].ray_facingright = 0;
		cub->rays[ray_id].wall_hit_x = 0;
		cub->rays[ray_id].wall_hit_y = 0;
		cub->rays[ray_id].wall_hitcontent = 0;
		cub->rays[ray_id].was_hitvertical = 0;
		cub->rays[ray_id].distance = 0;
		cub->rays[ray_id].minimap_dist = 0;
		cub->rays[ray_id].ray_angle = 0;
		ray_id ++;
	}
}
