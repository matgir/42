/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:34:10 by mgirardo          #+#    #+#             */
/*   Updated: 2022/06/07 17:34:14 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

int	quit(t_mlx *mlx)
{
	int	i;

	i = -1;
	while (++i < mlx->coord->line_count)
		free((mlx->coord->coord)[i]);
	free(mlx->coord->coord);
	free(mlx->coord);
	mlx_loop_end(mlx->mlx_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	free(mlx);
	exit(0);
}

void	press_esc(t_mlx *mlx)
{
	quit(mlx);
}

void	press_plus(t_mlx *mlx)
{
	if (mlx->coord->camera.z_scale > 1)
		mlx->coord->camera.z_scale -= 1;
	if (mlx->coord->camera.z_scale < 0)
		mlx->coord->camera.z_scale -= 1;
	if (mlx->coord->camera.z_scale == -20)
		mlx->coord->camera.z_scale = 20;
	display(mlx);
}

void	press_minus(t_mlx *mlx)
{
	if (mlx->coord->camera.z_scale < 20 && mlx->coord->camera.z_scale > 0)
		mlx->coord->camera.z_scale += 1;
	if (mlx->coord->camera.z_scale < -1 && mlx->coord->camera.z_scale < 0)
		mlx->coord->camera.z_scale += 1;
	if (mlx->coord->camera.z_scale == -20)
		mlx->coord->camera.z_scale = 20;
	display(mlx);
}

int	mouse_press(int click, int x, int y, t_mlx *mlx)
{
	(void) x;
	(void) y;
	if (click == WHEEL_UP)
		mlx->coord->camera.zoom += 1;
	if (click == WHEEL_DOWN)
	{
		if (mlx->coord->camera.zoom > 0)
			mlx->coord->camera.zoom -= 1;
	}
	display(mlx);
	return (0);
}
