/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <itahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 16:10:30 by itahani           #+#    #+#             */
/*   Updated: 2024/01/15 23:47:03 by itahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*------ changement de frame dès que pov bouge dans la map -------*/
void	update_img(t_vars *var)
{
	mlx_destroy_image(var->mlx, var->img.img);
	var->img.img = mlx_new_image(var->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	var->img.addr = mlx_get_data_addr(var->img.img, \
		&var->img.bits_per_pixel, &var->img.line_length, &var->img.endian);
	cast_all_rays(var);
	render_3d_map(var);
	render_minimap(var);
	mlx_put_image_to_window(var->mlx, var->win.win, var->img.img, 0, 0);
}

	/* at the beginning */
	// static int i = 0; //SUPPRIMER
	// printf("new fr[%i]\n", i++); //SUPPRIMER

/*------ action d'une touche pressée -------*/
// int	key_hook(int keycode, t_vars *var)
// {
// 	var->player.waldirection = 0;
// 	var->player.turndirection = 0;
// 	if (keycode == FORWARD)
// 		var->player.waldirection = 1;
// 	if (keycode == BACKWARD)
// 		var->player.waldirection = -1;
// 	if (keycode == LEFT || keycode == 65361)
// 		var->player.turndirection = -0.1;
// 	if (keycode == RIGHT || keycode == 65363)
// 		var->player.turndirection = 0.1;
// 	var->player.rotationangle += var->player.turndirection;
// 	var->player.rotationangle = normalize_angle(var->player.rotationangle);
// 	var->player.step = var->player.waldirection * var->player.movespeed;
// 	var->player.x += cos(var->player.rotationangle) * var->player.step;
// 	var->player.y += sin(var->player.rotationangle) * var->player.step;
// 	stop_wall(&var->player, var, keycode);
// 	if (keycode == ESC)
// 		free_mlx(var);
// 	if (keycode == FORWARD || keycode == BACKWARD
// 		|| keycode == LEFT || keycode == RIGHT
// 		|| keycode == 65361 || keycode == 65363)
// 		update_img(var);
// 	return (0);
// }

void	keycode_assign(t_vars *var, int i)
{
	if (i == 1 || i == 2)
	{
		if (i == 1)
			var->player.waldirection = 1;
		else if (i == 2)
			var->player.waldirection = -1;
		var->player.step = var->player.waldirection * var->player.movespeed;
		var->player.x += cos(var->player.rotationangle) * var->player.step;
		var->player.y += sin(var->player.rotationangle) * var->player.step;
	}
	if (i == 3 || i == 4)
	{
		if (i == 3)
			var->player.sidedirection = 1;
		else if (i == 4)
			var->player.sidedirection = -1;
		var->player.step = var->player.sidedirection * var->player.movespeed;
		var->player.x += cos(var->player.rotationangle + M_PI / 2)
			* var->player.step;
		var->player.y += sin(var->player.rotationangle + M_PI / 2)
			* var->player.step;
	}
}

int	key_hook(int keycode, t_vars *var)
{
	var->player.waldirection = 0;
	var->player.turndirection = 0;
	if (keycode == 65361)
		var->player.turndirection = -0.1;
	if (keycode == 65363)
		var->player.turndirection = 0.1;
	var->player.rotationangle += var->player.turndirection;
	var->player.rotationangle = normalize_angle(var->player.rotationangle);
	if (keycode == FORWARD)
		keycode_assign(var, 1);
	if (keycode == BACKWARD)
		keycode_assign(var, 2);
	if (keycode == RIGHT)
		keycode_assign(var, 3);
	if (keycode == LEFT)
		keycode_assign(var, 4);
	stop_wall(&var->player, var, keycode);
	if (keycode == ESC)
		free_mlx(var);
	if (keycode == FORWARD || keycode == BACKWARD
		|| keycode == LEFT || keycode == RIGHT
		|| keycode == 65361 || keycode == 65363)
		update_img(var);
	return (0);
}

	/* at the beginning */
	// static int i = 0; //SUPPRIMER
	// printf("keycode == %i\n", keycode);

	/* after update_img(var); */
	// printf("======== key pressed : %i ========\n", i); //SUPPRIMER
	// i++; //SUPPRIMER
