/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:12:17 by mgirardo          #+#    #+#             */
/*   Updated: 2024/01/15 15:12:18 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

// fonction qui permet de caster chaque rayon un par un en calculant les
	//intersections avec les murs + distances

void	assign_horhit_val(t_cast *cast, int i)
{
	if (i == 1)
	{
		cast->next_horizontal_x = cast->x_inter;
		cast->next_horizontal_y = cast->y_inter;
	}
	else if (i == 2)
	{
		cast->current_x = cast->next_horizontal_x;
		cast->current_y = cast->next_horizontal_y;
	}
	else if (i == 3)
	{
		cast->horizontal_hit_x = cast->next_horizontal_x;
		cast->horizontal_hit_y = cast->next_horizontal_y;
		cast->horizontal_content = 1;
		cast->horizontal_hit = 1;
	}
	else if (i == 4)
	{
		cast->next_horizontal_x += cast->x_step;
		cast->next_horizontal_y += cast->y_step;
	}
}

void	assign_verthit_val(t_cast *cast, int i)
{
	if (i == 1)
	{
		cast->next_vertical_x = cast->x_inter;
		cast->next_vertical_y = cast->y_inter;
	}
	else if (i == 2)
	{
		cast->current_x = cast->next_vertical_x;
		cast->current_y = cast->next_vertical_y;
	}
	else if (i == 3)
	{
		cast->vertical_hit_x = cast->next_vertical_x;
		cast->vertical_hit_y = cast->next_vertical_y;
		cast->vertical_content = 1;
		cast->vertical_hit = 1;
	}
	else if (i == 4)
	{
		cast->next_vertical_x += cast->x_step;
		cast->next_vertical_y += cast->y_step;
	}
}

static void	cast_ray(t_vars *cub, float ray_angle, t_ray *ray)
{
	t_cast	cast;

	get_ray_orientation(&cast, ray_angle);
	horizontal_step(cub, ray_angle, &cast);
	horizontal_hit(cub, &cast);
	vertical_step(cub, ray_angle, &cast);
	vertical_hit(cub, &cast);
	set_distance(cub, &cast);
	compare_distance(&cast, ray, ray_angle);
	adjust_distance(&cub->player, ray); // a retirer pour le rendu minimap
}

void	cast_all_rays(t_vars *cub)
{
	float	ray_angle;
	int		ray_id;

	ray_id = 0;
	// ray_angle = cub->player.rotationangle - (FOV_ANGLE / 2);
	while (ray_id < NUM_RAYS)
	{
		ray_angle = cub->player.rotationangle
			+ atan((ray_id - NUM_RAYS / 2) / ((WINDOW_WIDTH / 2)
					/ tan(FOV_ANGLE / 2)));
		// printf("angle == %f\n", ray_angle);
		cub->rays[ray_id].ray_angle = normalize_angle(ray_angle);
		cast_ray(cub, cub->rays[ray_id].ray_angle, &cub->rays[ray_id]);
		ray_angle += (FOV_ANGLE / NUM_RAYS);
		ray_id ++;
	}
	// printf("FIN\n");
}
