/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <itahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 18:31:08 by itahani           #+#    #+#             */
/*   Updated: 2024/01/14 21:05:31 by itahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../../cub3d.h"

/*
void	my_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->ll + x * (img->bits / 8));
	*(unsigned int *)dst = color;
}
*/

void	put_pix(t_data *img, int x, int y, int color)
{
	if ((x < WINDOW_WIDTH && y < WINDOW_HEIGHT) && (x >= 0 && y >= 0))
		*(int *)(img->addr + (y * img->line_length
					+ x * (img->bits_per_pixel / 8))) = color;
}

void	compose_wall_strip(t_vars *var, t_render *render, int i, t_data *text)
{
	int	x;
	int	y;
	int	limit_x;

	// (void)text; //SUPPRIMER
	x = i * render->wallstripwidth;
	limit_x = x + render->wallstripwidth;
	y = render->walltoppxl;
	while (y <= render->wallbottompxl)
	{
		render->distfromtop = y + (render->wallstripheight / 2)
			- (WINDOW_HEIGHT / 2);
		render->offset_y = render->distfromtop * ((float)TEXT_SIZE
				/ render->wallstripheight);
		render->pxl = *(int *)(text->addr + (render->offset_y
					* text->line_length + render->offset_x
					* (text->bits_per_pixel / 8)));
		x = i * render->wallstripwidth;
		while (x < limit_x)
		{
			if ((x < WINDOW_WIDTH && y < WINDOW_HEIGHT)
				&& (x >= 0 && y >= 0))
				put_pix(&var->img, x, y, render->pxl);
			x++;
		}
		y++;
	}
}

/*------ render des murs en 3d ------*/
void	render_walls(t_vars *var)
{
	int			i;
	t_render	render;
	t_ray		ray;
	t_data		*text;

	i = 0;
	while (i < NUM_RAYS)
	{
		ray = var->rays[i];
		text_offset_x(&ray, &render);
		render.dist_proj_plane = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
		render.wallstripheight = (TILE_SIZE / ray.distance)
			* render.dist_proj_plane;
		render.wallstripwidth = WALL_STRIP_WIDTH;
		render.walltoppxl = (WINDOW_HEIGHT / 2) - (render.wallstripheight / 2);
		if (render.walltoppxl < 0)
			render.walltoppxl = 0;
		render.wallbottompxl = (WINDOW_HEIGHT / 2)
			+ (render.wallstripheight / 2);
		if (render.wallbottompxl > WINDOW_HEIGHT)
			render.wallbottompxl = WINDOW_HEIGHT;
		text = get_texture(&ray, var);
		compose_wall_strip(var, &render, i, text);
		i++;
	}
	// printf("orientation du joueur == %f\n", var->player.rotationangle);
}
