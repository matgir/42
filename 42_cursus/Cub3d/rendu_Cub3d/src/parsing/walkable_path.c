/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walkable_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <itahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 19:54:46 by itahani           #+#    #+#             */
/*   Updated: 2024/01/17 15:06:41 by itahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	cross_wall_utils(t_player *player, t_vars *var, int *i)
{
	int	x;
	int	y;

	x = floor(player->trajectory.current_y / TILE_SIZE);
	y = floor(player->trajectory.current_x / TILE_SIZE);
	if (!var->map[x][y] || var->map[x][y] == 1 || var->map[x][y] == ' '
		|| margin_check(player, var->map, 1) == 1)
		return (1);
	player->trajectory.current_x += player->trajectory.xinc;
	player->trajectory.current_y += player->trajectory.yinc;
	*i += 1;
	return (0);
}

int	cross_wall(t_player *player, t_vars *var)
{
	int	i;

	i = 0;
	player->trajectory.delta_x = player->new_x - player->x;
	player->trajectory.delta_y = player->new_y - player->y;
	if (abs(player->trajectory.delta_x) >= abs(player->trajectory.delta_y))
		player->trajectory.sidelength = abs(player->trajectory.delta_x);
	else
		player->trajectory.sidelength = abs(player->trajectory.delta_y);
	player->trajectory.xinc = player->trajectory.delta_x
		/ (float)player->trajectory.sidelength;
	player->trajectory.yinc = player->trajectory.delta_y
		/ (float)player->trajectory.sidelength;
	player->trajectory.current_x = player->x;
	player->trajectory.current_y = player->y;
	while (i < player->trajectory.sidelength)
		if (cross_wall_utils(player, var, &i) == 1)
			return (1);
	return (0);
}

int	margin_check(t_player *player, char	**map, int i)
{
	float	x;
	float	y;
	float	margin;

	margin = 0.3;
	if (i == 1)
	{
		x = player->trajectory.current_y;
		y = player->trajectory.current_x;
	}
	else
	{
		x = player->new_y;
		y = player->new_x;
	}
	if (map[(int)((x + margin) / TILE_SIZE)][(int)((y + margin)
		/ TILE_SIZE)] == '1' || map[(int)((x - margin) / TILE_SIZE)]
		[(int)((y - margin) / TILE_SIZE)] == '1' || map[(int)((x + margin)
		/ TILE_SIZE)][(int)((y - margin) / TILE_SIZE)] == '1'
		|| map[(int)((x - margin) / TILE_SIZE)][(int)((y + margin)
		/ TILE_SIZE)] == '1')
		return (1);
	return (0);
}

void	stop_wall(t_player *player, t_vars *var)
{
	int		x;
	int		y;

	x = floor(player->new_y / TILE_SIZE);
	y = floor(player->new_x / TILE_SIZE);
	if ((player->new_x > (WINDOW_WIDTH * TILE_SIZE) || player->new_x < 0)
		|| (player->new_y > (WINDOW_HEIGHT * TILE_SIZE) || player->new_y < 0)
		|| !var->map[x][y] || var->map[x][y] == '1'
		|| var->map[x][y] == ' ' || cross_wall(player, var) != 0
		|| margin_check(player, var->map, 0) == 1)
		;
	else
	{
		player->x = player->new_x;
		player->y = player->new_y;
	}
}
