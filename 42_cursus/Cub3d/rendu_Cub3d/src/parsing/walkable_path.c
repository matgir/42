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

int	cross_wall(t_player *player, t_vars *var) // ajouter au .h //AJOUT
{
	int	i;
	int	x;
	int	y;

	i = 0;
	player->trajectory.delta_x = player->new_x - player->x;
	player->trajectory.delta_y = player->new_y - player->y;
	if (abs(player->trajectory.delta_x) >= abs(player->trajectory.delta_y))
		player->trajectory.sidelength = abs(player->trajectory.delta_x);
	else
		player->trajectory.sidelength = abs(player->trajectory.delta_y);
	player->trajectory.xinc = player->trajectory.delta_x / (float)player->trajectory.sidelength;
	player->trajectory.yinc = player->trajectory.delta_y / (float)player->trajectory.sidelength;
	player->trajectory.current_x = player->x;
	player->trajectory.current_y = player->y;
	while (i < player->trajectory.sidelength)
	{
		x = floor(player->trajectory.current_y / TILE_SIZE);
		y = floor(player->trajectory.current_x / TILE_SIZE);
		if (var->map[x][y] == '1')
			return (1);
		
		player->trajectory.current_x += player->trajectory.xinc;
		player->trajectory.current_y += player->trajectory.yinc;
		i++;
	}
	return (0);
}

// void	reverse_pos_for_back(t_player *player, int keycode)
// {
// 	if (keycode == FORWARD)
// 		player->waldirection = -1;
// 	else if (keycode == BACKWARD)
// 		player->waldirection = 1;
// 	player->step = player->waldirection * player->movespeed;
// 	player->x += cos(player->rotationangle) * player->step;
// 	player->y += sin(player->rotationangle) * player->step;
// }

// void	reverse_pos_left_right(t_player *player/* , int keycode */)
// {
// 	if (keycode == LEFT)
// 		player->sidedirection = 1;
// 	else if (keycode == RIGHT)
// 		player->sidedirection = -1;
// 	player->step = player->sidedirection * player->movespeed;
// 	player->x += cos(player->rotationangle + M_PI / 2) * player->step;
// 	player->y += sin(player->rotationangle + M_PI / 2) * player->step;
// }

void	stop_wall(t_player *player, t_vars *var/* , int keycode */)
{
	int		x;
	int		y;

	x = floor(player->new_y / TILE_SIZE);
	y = floor(player->new_x / TILE_SIZE);
	if (var->map[x][y] && var->map[x][y] != '1' && var->map[x][y] != ' '
			&& cross_wall(player, var) == 0)
	// if (var->map[x][y] == '1')
	{
		player->x = player->new_x;
		player->y = player->new_y;
		// if (keycode == FORWARD || keycode == BACKWARD)
		// 	reverse_pos_for_back(player, keycode);
		// if (keycode == LEFT || keycode == RIGHT)
		// 	reverse_pos_left_right(player, keycode);
	}
}

	// float	angle;

/* before if */
	// angle = var->rays[NUM_RAYS / 2].ray_angle;
	// if (((player->y / TILE_SIZE) == x) && (angle >= M_PI))
	// 	x--;
	// if (((player->x / TILE_SIZE) == y) && ((angle > M_PI / 2)
	// 		|| angle < 3 * (M_PI / 2)))
	// 	y--;