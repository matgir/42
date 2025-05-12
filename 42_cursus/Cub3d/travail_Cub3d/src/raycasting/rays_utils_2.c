/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:50:29 by mgirardo          #+#    #+#             */
/*   Updated: 2024/01/17 16:50:31 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/* les fonctions suivantes vont calculer les intersections avec les murs en
	fonctions de nos coordonnees et l'orientation du rayon */

void	horizontal_step(t_vars *cub, float ray_angle, t_cast *cast)
{
	cast->horizontal_content = 0;
	cast->horizontal_hit = 0;
	cast->horizontal_hit_x = 0;
	cast->horizontal_hit_y = 0;
	cast->y_inter = floor(cub->player.y / TILE_SIZE) * TILE_SIZE;
	if (cast->ray_facingdown)
		cast->y_inter += TILE_SIZE;
	cast->x_inter = cub->player.x
		+ (cast->y_inter - cub->player.y) / tan(ray_angle);
	cast->y_step = TILE_SIZE;
	if (cast->ray_facingup)
		cast->y_step *= -1;
	cast->x_step = TILE_SIZE / tan(ray_angle);
	if (cast->ray_facingleft && cast->x_step > 0)
		cast->x_step *= -1;
	if (cast->ray_facingright && cast->x_step < 0)
		cast->x_step *= -1;
}

void	horizontal_hit(t_vars *cub, t_cast *cast)
{
	int	wall;

	wall = 0;
	assign_horhit_val(cast, 1);
	while (cast->next_horizontal_x >= 0 && cast->next_horizontal_y >= 0
		&& cast->next_horizontal_x < (cub->win.width)
		&& cast->next_horizontal_y < (cub->win.height))
	{
		assign_horhit_val(cast, 2);
		if (cast->ray_facingup)
			cast->current_y --;
		else
			cast->current_y = cast->next_horizontal_y;
		wall = is_wall(cub, cast->current_x, cast->current_y);
		if (wall)
		{
			if (wall == 1)
				assign_horhit_val(cast, 3);
			break ;
		}
		else
			assign_horhit_val(cast, 4);
	}
}

void	vertical_step(t_vars *cub, float ray_angle, t_cast *cast)
{
	cast->vertical_hit = 0;
	cast->vertical_content = 0;
	cast->vertical_hit_x = 0;
	cast->vertical_hit_y = 0;
	cast->x_inter = floor(cub->player.x / TILE_SIZE) * TILE_SIZE;
	if (cast->ray_facingright)
		cast->x_inter += TILE_SIZE;
	cast->y_inter = cub->player.y
		+ (cast->x_inter - cub->player.x) * tan(ray_angle);
	cast->x_step = TILE_SIZE;
	if (cast->ray_facingleft)
		cast->x_step *= -1;
	cast->y_step = TILE_SIZE * tan(ray_angle);
	if (cast->ray_facingup && cast->y_step > 0)
		cast->y_step *= -1;
	if (cast->ray_facingdown && cast->y_step < 0)
		cast->y_step *= -1;
}

void	vertical_hit(t_vars *cub, t_cast *cast)
{
	int	wall;

	wall = 0;
	assign_verthit_val(cast, 1);
	while (cast->next_vertical_x >= 0 && cast->next_vertical_y >= 0
		&& cast->next_vertical_x < (cub->win.width)
		&& cast->next_vertical_y < (cub->win.height))
	{
		assign_verthit_val(cast, 2);
		if (cast->ray_facingleft)
			cast->current_x --;
		cast->current_y = cast->next_vertical_y;
		wall = is_wall(cub, cast->current_x, cast->current_y);
		if (wall)
		{
			if (wall == 1)
				assign_verthit_val(cast, 3);
			break ;
		}
		else
			assign_verthit_val(cast, 4);
	}
}
