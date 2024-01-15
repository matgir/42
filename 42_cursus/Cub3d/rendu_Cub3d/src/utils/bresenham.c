/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <itahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 19:20:44 by itahani           #+#    #+#             */
/*   Updated: 2024/01/11 15:32:28 by itahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

// Algorithme de Bresenham pour tracer une ligne
void vision_line(t_data *img, t_player *player, int color)
{
	int	x0;
	int	y0;
	int  x1;
	int	y1;

	x0 = player->x;
	y0 = player->y;
	x1 = x0 + (cos(player->rotationAngle) * 30);
	y1 = y0 + (sin(player->rotationAngle) * 30);
    // printf("rotation angle == %f     |      ", player->rotationAngle);
    // printf("x1 == %f y1 == %f\n", x1, y1);
	
	int dx = fabs((float)x1 - (float)x0);
    int dy = fabs((float)y1 - (float)y0);
    int sx, sy;

    if (x0 < x1) {
        sx = 1;
    } else {
        sx = -1;
    }

    if (y0 < y1) {
        sy = 1;
    } else {
        sy = -1;
    }

    int err = dx - dy;

    while (x0 != x1 || y0 != y1) {
        my_mlx_pixel_put(img, x0, y0, color);
        int err2 = 2 * err;

        if (err2 > -dy) {
            err -= dy;
            x0 += sx;
        }

        if (err2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
}


void	render_FOV(t_vars *cub, t_player *player, int color)
{
	int i;
	int	x0;
	int	y0;
	int  x1;
	int	y1;

	i = 0;
	while (i < NUM_RAYS) // remettre NUM_RAYS
	{
		if (i == NUM_RAYS/2) //SUPPRIMER
			color = 0xFF0000; //SUPPRIMER
		else 
			color = 0x00FF00;
		x0 = player->x;
		y0 = player->y;
		x1 = x0 + (cos(cub->rays[i].ray_angle) * cub->rays[i].distance);
		y1 = y0 + (sin(cub->rays[i].ray_angle) * cub->rays[i].distance);
		// x1 = x0 + (cos(cub->rays[i].ray_angle) * cub->rays[i].distance);
		// y1 = y0 + (sin(cub->rays[i].ray_angle) * cub->rays[i].distance);
		// printf("DISTANCE==== %f\n", cub->rays[i].distance);

		int dx = fabs((float)x1 - (float)x0);
    	int dy = fabs((float)y1 - (float)y0);
    	int sx, sy;

    	if (x0 < x1) {
    	    sx = 1;
    	} else {
    	    sx = -1;
    	}

    	if (y0 < y1) {
    	    sy = 1;
    	} else {
    	    sy = -1;
    	}

    	int err = dx - dy;

    	while (x0 != x1 || y0 != y1) {
			//printf("x0 == %i | y0 == %i\n", x0, y0);
    	    my_mlx_pixel_put(&cub->img, x0, y0, color);
    	    int err2 = 2 * err;

    	    if (err2 > -dy) {
    	        err -= dy;
    	        x0 += sx;
    	    }

    	    if (err2 < dx) {
    	        err += dx;
    	        y0 += sy;
    	    }
    	}
		i++;
	}
}
