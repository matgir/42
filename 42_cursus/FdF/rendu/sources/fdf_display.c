/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:28:38 by mgirardo          #+#    #+#             */
/*   Updated: 2022/06/07 17:28:41 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

int	free_and_quit_img(t_mlx *mlx)
{
	int	i;

	if (mlx->mlx_ptr && mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (mlx->mlx_ptr)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
	}
	i = -1;
	while (++i < mlx->coord->line_count)
		free((mlx->coord->coord)[i]);
	free(mlx->coord->coord);
	free(mlx->coord);
	free(mlx);
	return (0);
}

void	put_to_img(t_mlx *mlx, t_img *img)
{
	int		i;
	int		j;
	t_iso	p;

	i = -1;
	while (++i < mlx->coord->line_count)
	{
		j = -1;
		while (++j < mlx->coord->column_count)
		{
			p = init_iso(j, i, mlx->coord->coord[i][j]);
			if (j > 0)
				trace_line(project(p, mlx->coord), project(init_iso(j - 1, i,
							mlx->coord->coord[i][j - 1]), mlx->coord), img);
			if (i > 0)
				trace_line(project(p, mlx->coord), project(init_iso(j, i - 1,
							mlx->coord->coord[i - 1][j]), mlx->coord), img);
		}
	}
}

int	display(t_mlx *mlx)
{
	t_img	img;

	img.img_ptr = mlx_new_image(mlx->mlx_ptr, WHIDTH, HEIGHT);
	if (img.img_ptr == NULL)
		return (free_and_quit_img(mlx));
	img.addr = mlx_get_data_addr(img.img_ptr, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	if (mlx->coord->z_range == -10)
		*(mlx->coord) = init_map(*(mlx->coord));
	put_to_img(mlx, &img);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img.img_ptr, 0, 0);
	mlx_destroy_image(mlx->mlx_ptr, img.img_ptr);
	return (1);
}

t_mlx	*free_and_quit(t_mlx *mlx)
{
	int	i;

	i = -1;
	while (++i < mlx->coord->line_count)
		free((mlx->coord->coord)[i]);
	free(mlx->coord->coord);
	free(mlx->coord);
	free(mlx);
	return (NULL);
}

t_mlx	*free_and_quit_win(t_mlx *mlx)
{
	int	i;

	
	i = -1;
	while (++i < mlx->coord->line_count)
		free((mlx->coord->coord)[i]);
	free(mlx->coord->coord);
	free(mlx->coord);
	if (mlx->mlx_ptr)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
	}
	free(mlx);
	return (NULL);
}

t_mlx	*display_fdf(char *win_name, t_coord *coord)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (mlx == NULL)
		return (NULL);
	mlx->coord = coord;
	mlx->coord->z_range = -10;
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		return (free_and_quit(mlx));
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WHIDTH, HEIGHT, win_name);
	if (mlx->win_ptr == NULL)
		return (free_and_quit_win(mlx));
	mlx_key_hook(mlx->win_ptr, key_press, mlx);
	mlx_mouse_hook(mlx->win_ptr, mouse_press, mlx);
	mlx_hook(mlx->win_ptr, 17, 0, quit, mlx);
	if (display(mlx) == 0)
		return (NULL);
	mlx_loop(mlx->mlx_ptr);
	return (mlx);
}
