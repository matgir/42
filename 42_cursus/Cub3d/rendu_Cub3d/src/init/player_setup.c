/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <itahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 22:55:45 by itahani           #+#    #+#             */
/*   Updated: 2024/01/15 23:47:16 by itahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/*------ coordonnées de départ du joueur -------*/
void	start_position(t_vars *var, t_player *player)
{
	int		x;
	int		y;

	x = -1;
	while (var->map[++x])
	{
		y = -1;
		while (var->map[x][++y])
		{	
			if (var->map[x][y] == 'N' || var->map[x][y] == 'S'
				|| var->map[x][y] == 'W' || var->map[x][y] == 'E')
			{
				player->x = y * TILE_SIZE + (TILE_SIZE / 2);
				player->y = x * TILE_SIZE + (TILE_SIZE / 2);
			}
		}
	}
}

/*------ orientation de départ du joueur -------*/
void	start_orientation(t_vars *var, t_player *player)
{
	int		x;
	int		y;
	char	orientation;

	x = (player->y - (TILE_SIZE / 2)) / TILE_SIZE;
	y = (player->x - (TILE_SIZE / 2)) / TILE_SIZE;
	orientation = var->map[x][y];
	if (orientation == 'N')
		player->rotationangle = (3 * M_PI) / 2;
	else if (orientation == 'S')
		player->rotationangle = M_PI_2;
	else if (orientation == 'E')
		player->rotationangle = M_PI * 2;
	else if (orientation == 'W')
		player->rotationangle = M_PI;
}

/*------ joueur part du milieu de map et regarde vers le sud -------*/
void	init_player(t_player *player, t_vars *var)
{
	player->radius = 10;
	start_position(var, player);
	start_orientation(var, player);
	player->turndirection = 0;
	player->waldirection = 0;
	player->sidedirection = 0;
	player->step = 0;
	player->movespeed = 3.0;
	player->rotationspeed = 2 * (M_PI / 180);
	player->new_x = player->x;
	player->new_y = player->y;
}
