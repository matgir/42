/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <itahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 20:27:01 by itahani           #+#    #+#             */
/*   Updated: 2024/01/14 22:25:13 by itahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

// afficher une texture unique pour commencer sur tous les murs.

// void	text_to_wall(t_vars *var, int x, int y)
// {
// 	int	i;
// 	int	j;
// 	i = ;
// 	j = ;
/* 	int pxl = *(int *)(text.addr + (i * text.line_length + j
	* (text.bits_per_pixel / 8))); */
// 	put_pix(&var->img, x, y, pxl);
// }

void	destroy_textures(t_vars *var)
{
	mlx_destroy_image(var->mlx, var->text[0].img);
	mlx_destroy_image(var->mlx, var->text[1].img);
	mlx_destroy_image(var->mlx, var->text[2].img);
	mlx_destroy_image(var->mlx, var->text[3].img);
}

void	init_textures(t_vars *var)
{
	var->text[0].img = mlx_xpm_file_to_image(var->mlx, var->config.north, \
			&var->text[0].bits_per_pixel, &var->text[0].line_length);
	var->text[0].addr = mlx_get_data_addr(var->text[0].img,
			&var->text[0].bits_per_pixel, &var->text[0].line_length,
			&var->text[0].endian);
	var->text[1].img = mlx_xpm_file_to_image(var->mlx, var->config.south, \
			&var->text[1].bits_per_pixel, &var->text[1].line_length);
	var->text[1].addr = mlx_get_data_addr(var->text[1].img,
			&var->text[1].bits_per_pixel, &var->text[1].line_length,
			&var->text[1].endian);
	var->text[2].img = mlx_xpm_file_to_image(var->mlx, var->config.west, \
			&var->text[2].bits_per_pixel, &var->text[2].line_length);
	var->text[2].addr = mlx_get_data_addr(var->text[2].img,
			&var->text[2].bits_per_pixel, &var->text[2].line_length,
			&var->text[2].endian);
	var->text[3].img = mlx_xpm_file_to_image(var->mlx, var->config.east, \
			&var->text[3].bits_per_pixel, &var->text[3].line_length);
	var->text[3].addr = mlx_get_data_addr(var->text[3].img,
			&var->text[3].bits_per_pixel, &var->text[3].line_length,
			&var->text[3].endian);
}

t_data	*get_texture(t_ray *ray, t_vars *var)
{
	t_data	*texture;

	if (ray->ray_facingdown && !ray->was_hitvertical)
		texture = &var->text[0];
	else if (ray->ray_facingup && !ray->was_hitvertical)
		texture = &var->text[1];
	else if (ray->ray_facingleft && ray->was_hitvertical)
		texture = &var->text[2];
	else
		texture = &var->text[3];
	return (texture);
	// else if (ray->ray_facingright)
}

void	text_offset_x(t_ray *ray, t_render *render)
{
	if (ray->was_hitvertical)
		render->offset_x = (int)ray->wall_hit_y % TILE_SIZE;
	else
		render->offset_x = (int)ray->wall_hit_x % TILE_SIZE;
}
