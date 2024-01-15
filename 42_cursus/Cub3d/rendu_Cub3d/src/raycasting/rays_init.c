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

#include "../includes/cub3d.h"

void	init_rays(t_vars *cub)
{
	int	ray_id;

	ray_id = 0;
	while (ray_id < NUM_RAYS)
	{
		cub->rays[ray_id].ray_facingDown = 0;
		cub->rays[ray_id].ray_facingUp = 0;
		cub->rays[ray_id].ray_facingLeft = 0;
		cub->rays[ray_id].ray_facingRight = 0;
		cub->rays[ray_id].wall_hit_x = 0;
		cub->rays[ray_id].wall_hit_y = 0;
		cub->rays[ray_id].wall_hitContent = 0;
		cub->rays[ray_id].was_hitVertical = 0;
		ray_id ++;
	}
}
