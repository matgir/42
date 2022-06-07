/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:34:20 by mgirardo          #+#    #+#             */
/*   Updated: 2022/06/07 17:34:22 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

void	press_w(t_mlx *mlx)
{
	mlx->coord->camera.y_offset -= 25;
	display(mlx);
}

void	press_a(t_mlx *mlx)
{
	mlx->coord->camera.x_offset -= 25;
	display(mlx);
}

void	press_s(t_mlx *mlx)
{
	mlx->coord->camera.y_offset += 25;
	display(mlx);
}

void	press_d(t_mlx *mlx)
{
	mlx->coord->camera.x_offset += 25;
	display(mlx);
}

int	key_press(int key, void *ptr)
{
	if (key == ESC)
		press_esc((t_mlx *) ptr);
	if (key == PLUS)
		press_plus((t_mlx *) ptr);
	if (key == MINUS)
		press_minus((t_mlx *) ptr);
	if (key == W)
		press_w((t_mlx *) ptr);
	if (key == A)
		press_a((t_mlx *) ptr);
	if (key == S)
		press_s((t_mlx *) ptr);
	if (key == D)
		press_d((t_mlx *) ptr);
	return (0);
}