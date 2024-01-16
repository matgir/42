/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walkable_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <itahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:54:46 by itahani           #+#    #+#             */
/*   Updated: 2024/01/15 23:05:39 by itahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

// void	stop_wall(t_player *player, t_vars *var, int keycode)
// {
// 	int		x;
// 	int		y;
// 	float	angle;

// 	x = floor(player->y / TILE_SIZE);
// 	y = floor(player->x / TILE_SIZE);
// 	angle = var->rays[NUM_RAYS / 2].ray_angle;
// 	if (((player->y / TILE_SIZE) == x) && (angle >= M_PI))
// 		x--;
// 	if (((player->x / TILE_SIZE) == y) && ((angle > M_PI / 2)
// 			|| angle < 3 * (M_PI / 2)))
// 		y--;
// 	if (var->map[x][y] == '1')
// 	{
// 		if (keycode == FORWARD)
// 			player->waldirection = -1;
// 		else if (keycode == BACKWARD)
// 			player->waldirection = 1;
// 		player->step = player->waldirection * player->movespeed;
// 		player->x += cos(player->rotationangle) * player->step;
// 		player->y += sin(player->rotationangle) * player->step;
// 	}
// }

void	stop_wall(t_player *player, t_vars *var, int keycode)
{
	int		x;
	int		y;
	// float	angle;

	x = floor(player->y / TILE_SIZE);
	y = floor(player->x / TILE_SIZE);
	// angle = var->rays[NUM_RAYS / 2].ray_angle;
	// if (((player->y / TILE_SIZE) == x) && (angle >= M_PI))
	// 	x--;
	// if (((player->x / TILE_SIZE) == y) && ((angle > M_PI / 2)
	// 		|| angle < 3 * (M_PI / 2)))
	// 	y--;
	if (var->map[x][y] == '1')
	{
		if (keycode == FORWARD || keycode == BACKWARD)
		{
			if (keycode == FORWARD)
				player->waldirection = -1;
			else if (keycode == BACKWARD)
				player->waldirection = 1;
			player->step = player->waldirection * player->movespeed;
			player->x += cos(player->rotationangle) * player->step;
			player->y += sin(player->rotationangle) * player->step;
		}
		if (keycode == LEFT || keycode == RIGHT)
		{
			if (keycode == LEFT)
				player->sidedirection = 1;
			else if (keycode == RIGHT)
				player->sidedirection = -1;
			player->step = player->sidedirection * player->movespeed;
			player->x += cos(player->rotationangle + M_PI/2) * player->step;
			player->y += sin(player->rotationangle + M_PI/2) * player->step;
		}
	}
}