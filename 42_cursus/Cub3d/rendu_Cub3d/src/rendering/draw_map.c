/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <itahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:34:57 by itahani           #+#    #+#             */
/*   Updated: 2024/01/17 16:08:25 by itahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	compose_floor(t_vars *var)
{
	int		x;
	int		y;

	x = -1;
	while (var->map[++x])
	{
		y = -1;
		while (var->map[x][++y])
		{	
			if (var->map[x][y] == '0' || var->map[x][y] == 'N'
				|| var->map[x][y] == 'S' || var->map[x][y] == 'W'
				|| var->map[x][y] == 'E')
				draw_square(var, x, y, 0x00FFFFFF);
		}
	}
}

void	compose_wall(t_vars *var)
{
	int		x;
	int		y;

	x = -1;
	while (var->map[++x])
	{
		y = -1;
		while (var->map[x][++y])
		{
			if (var->map[x][y] == '1')
				draw_square(var, x, y, 0x363636);
		}
	}
}

void	composer_map(t_vars *var)
{
	compose_floor(var);
	render_fov(var, &var->player, 0x00FF00);
	compose_wall(var);
	show_player_on_minimap(&var->player, var);
}

/*
void	composer_map(t_vars *var)
{
	int		x;
	int		y;

	x = -1;
	while (var->map[++x])
	{
		y = -1;
		while (var->map[x][++y])
		{	
			if (var->map[x][y] == '0' || var->map[x][y] == 'N'
				|| var->map[x][y] == 'S' || var->map[x][y] == 'W'
				|| var->map[x][y] == 'E')
				draw_square(var, x, y, 0x00FFFFFF);
			else if (var->map[x][y] == '1')
				draw_square(var, x, y, 0x363636);
		}
	}
}
*/
