/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <itahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:34:57 by itahani           #+#    #+#             */
/*   Updated: 2024/01/13 19:10:44 by itahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*------ composer une image pxl par pxl puis 
afficher en une fois avec mlx_put_image_to_window -------*/
void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	x = x * 0.08;
	y = y * 0.08;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/*------ composer les carrés 2d -------*/
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
			my_mlx_pixel_put(&var->img, j, i, color);
			j++;
		}
		i++;
	}
}

/*------ composer la grille 2d -------*/
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
				my_mlx_pixel_put(&var->img, j, i, color);
			j++;
		}
		i++;
	}
}

/*------ représentation 2d du joueur par un carré de côté 'radius' -------*/
void	show_player_on_minimap(t_player *player, t_vars *var)
{
	int	i;
	int	limit_i;
	int	j;
	int	limit_j;

	i = player->x - (player->radius / 2);
	limit_i = i + player->radius;
	my_mlx_pixel_put(&var->img, i, player->y - (player->radius / 2), 0xda0722);
	while (i <= limit_i)
	{
		j = player->y - (player->radius / 2);
		limit_j = j + player->radius;
		while (j <= limit_j)
		{
			my_mlx_pixel_put(&var->img, i, j, 0xda0722);
			j++;
		}
		i++;
	}
}

/* the if is for the ground and the esle if is for the wall */
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
			// draw_grid(var, x, y, 0x363636);
			// voir si on fait la minimap sans la grille
		}
	}
}
