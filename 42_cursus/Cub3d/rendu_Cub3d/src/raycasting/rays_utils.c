/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:11:46 by mgirardo          #+#    #+#             */
/*   Updated: 2024/01/15 15:11:51 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/*---------normaliser / "convertir" l'angle entre un range de 0 et 2PI-------*/

float	normalize_angle(float angle)
{
	angle = remainder(angle, TWO_PI);
	if (angle < 0)
		angle = TWO_PI + angle;
	return (angle);
}

/*-----------initialiser l'orientation du rayon---------------*/

void	get_ray_orientation(t_cast *cast, float ray_angle)
{
	cast->ray_facingdown = 0;
	cast->ray_facingup = 0;
	cast->ray_facingleft = 0;
	cast->ray_facingright = 0;
	if (ray_angle > 0 && ray_angle < M_PI)
		cast->ray_facingdown = 1;
	else
		cast->ray_facingup = !cast->ray_facingdown;
	if (ray_angle < 0.5 * M_PI || ray_angle > 1.5 * M_PI)
		cast->ray_facingright = 1;
	else
		cast->ray_facingleft = !cast->ray_facingright;
}

int	mapped_region(t_vars *var, int x, int y)
{
	int	i;

	i = 0;
	while (var->map[x][i])
		i++;
	i--;
	if (i < y)
		return (1);
	return (0);
}

/*--reperer s'il y a un mur, va etre utile pour les fonctions suivantes pour
	calculer les distances et les intersections---*/

int	is_wall(t_vars *cub, float x, float y)
{
	int	map_x;
	int	map_y;

	if (x < 0 || y < 0)
		return (1);
	map_x = y / TILE_SIZE;
	map_y = x / TILE_SIZE;
	// if (x > cub->mapwidth - 1)
	// 	return (1);
	// if (y > cub->mapheight - 1)
	// 	return (1);
	if (mapped_region(cub, map_x, map_y) == 1)
		return (2);
	if (cub->map[map_x][map_y] == '1')
		return (1);
	return (0);
}

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
	cast->next_horizontal_x = cast->x_inter;
	cast->next_horizontal_y = cast->y_inter;
	while (cast->next_horizontal_x >= 0 && cast->next_horizontal_y >= 0
		&& cast->next_horizontal_x < (cub->win.width)
		&& cast->next_horizontal_y < (cub->win.height))
	{
		cast->current_x = cast->next_horizontal_x;
		cast->current_y = cast->next_horizontal_y;
		if (cast->ray_facingup)
			cast->current_y --;
		else
			cast->current_y = cast->next_horizontal_y;
/*  */	if ((wall = is_wall(cub, cast->current_x, cast->current_y)))
		{
			if (wall == 1)
			{
				cast->horizontal_hit_x = cast->next_horizontal_x;
				cast->horizontal_hit_y = cast->next_horizontal_y;
				cast->horizontal_content = 1;
				cast->horizontal_hit = 1;
			}
			break ;
		}
		else
		{
			cast->next_horizontal_x += cast->x_step;
			cast->next_horizontal_y += cast->y_step;
		}
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
	cast->next_vertical_x = cast->x_inter;
	cast->next_vertical_y = cast->y_inter;
	while (cast->next_vertical_x >= 0 && cast->next_vertical_y >= 0
		&& cast->next_vertical_x < (cub->win.width)
		&& cast->next_vertical_y < (cub->win.height))
	{
		cast->current_x = cast->next_vertical_x;
		cast->current_y = cast->next_vertical_y;
		if (cast->ray_facingleft)
			cast->current_x --;
		cast->current_y = cast->next_vertical_y;
/*  */	if ((wall = is_wall(cub, cast->current_x, cast->current_y)))
		{
			if (wall == 1)
			{
				cast->vertical_hit_x = cast->next_vertical_x;
				cast->vertical_hit_y = cast->next_vertical_y;
				cast->vertical_content = 1;
				cast->vertical_hit = 1;
			}
			break ;
		}
		else
		{
			cast->next_vertical_x += cast->x_step;
			cast->next_vertical_y += cast->y_step;
		}
	}
}

/*float	distance_calculus(float p_x, float ray_angle, float hit_x)
{
	float	distance;
	distance = (p_x - hit_x) / cos(ray_angle);
	if (distance < 0)
		distance = floor(distance * (-1));
	else
		distance = floor(distance);
	return (distance);
}*/

float	distance_calculus(float p_x, float p_y, float hit_x, float hit_y)
{
	return (sqrt((hit_x - p_x) * (hit_x - p_x)
			+ (hit_y - p_y) * (hit_y - p_y)));
}

void	set_distance(t_vars *cub, t_cast *cast)
{
	if (cast->horizontal_hit)
		cast->horizontal_hit_distance = distance_calculus(cub->player.x,
				cub->player.y, cast->horizontal_hit_x, cast->horizontal_hit_y);
	else
		cast->horizontal_hit_distance = (float)INT_MAX;
	if (cast->vertical_hit)
		cast->vertical_hit_distance = distance_calculus(cub->player.x,
				cub->player.y, cast->vertical_hit_x, cast->vertical_hit_y);
	else
		cast->vertical_hit_distance = (float)INT_MAX;
}

void	compare_distance(t_cast *cast, t_ray *ray, float ray_angle)
{
	if (cast->vertical_hit_distance < cast->horizontal_hit_distance)
	{
		ray->distance = cast->vertical_hit_distance;
		ray->wall_hit_x = cast->vertical_hit_x;
		ray->wall_hit_y = cast->vertical_hit_y;
		ray->wall_hitcontent = cast->vertical_content;
		ray->was_hitvertical = 1;
	}
	else
	{
		ray->distance = cast->horizontal_hit_distance;
		ray->wall_hit_x = cast->horizontal_hit_x;
		ray->wall_hit_y = cast->horizontal_hit_y;
		ray->was_hitvertical = 0;
		ray->wall_hitcontent = cast->horizontal_content;
	}
	ray->ray_angle = ray_angle;
	ray->ray_facingdown = cast->ray_facingdown;
	ray->ray_facingup = cast->ray_facingup;
	ray->ray_facingleft = cast->ray_facingleft;
	ray->ray_facingright = cast->ray_facingright;
}

void	adjust_distance(t_player *player, t_ray *ray)
{
	ray->minimap_dist = ray->distance;
	ray->distance *= cos(ray->ray_angle - player->rotationangle);
}
