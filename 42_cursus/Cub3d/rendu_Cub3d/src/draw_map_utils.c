/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:58:59 by mgirardo          #+#    #+#             */
/*   Updated: 2024/01/17 16:59:00 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	my_mlx_pixel_put(t_vars *var, int x, int y, int color)
{
	put_pix(&var->img, x * var->scale_minimap, y * var->scale_minimap, color);
}

void	draw_square(t_vars *var, int x, int y, int color)
{
	int	i;
	int	limit_i;
	int	j;
	int	limit_j;

	i = TILE_SIZE * x;
	limit_i = i + TILE_SIZE;
	while (i < limit_i)
	{
		j = TILE_SIZE * y;
		limit_j = j + TILE_SIZE;
		while (j < limit_j)
		{
			my_mlx_pixel_put(var, j, i, color);
			j++;
		}
		i++;
	}
}

void	draw_grid(t_vars *var, int x, int y, int color)
{
	int	i;
	int	limit_i;
	int	j;
	int	limit_j;

	i = TILE_SIZE * x;
	limit_i = i + TILE_SIZE;
	while (i < limit_i)
	{
		j = TILE_SIZE * y;
		limit_j = j + TILE_SIZE;
		while (j < limit_j)
		{
			if (i % TILE_SIZE == 0 || j % TILE_SIZE == 0)
				my_mlx_pixel_put(var, j, i, color);
			j++;
		}
		i++;
	}
}

void	show_player_on_minimap(t_player *player, t_vars *var)
{
	int	i;
	int	limit_i;
	int	j;
	int	limit_j;

	i = player->x - (player->radius / 2);
	limit_i = i + player->radius;
	my_mlx_pixel_put(var, i, player->y - (player->radius / 2), 0xda0722);
	while (i <= limit_i)
	{
		j = player->y - (player->radius / 2);
		limit_j = j + player->radius;
		while (j <= limit_j)
		{
			my_mlx_pixel_put(var, i, j, 0xda0722);
			j++;
		}
		i++;
	}
}
