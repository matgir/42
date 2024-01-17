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
	angle = remainder(angle, (M_PI * 2));
	if (angle < 0)
		angle = (M_PI * 2) + angle;
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
	if (mapped_region(cub, map_x, map_y) == 1)
		return (2);
	if (cub->map[map_x][map_y] == '1')
		return (1);
	return (0);
}
