/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_floor_ceiling.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <itahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 21:58:19 by itahani           #+#    #+#             */
/*   Updated: 2023/11/12 22:58:22 by itahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	render_floor(t_vars *var, int y, int color)
{
	int	x;

	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			put_pix(&var->img, x, y, color);
			x++;
		}
		y++;
	}
}

void	render_ceiling(t_vars *var, int y, int color)
{
	int	x;

	while (y >= 0)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			put_pix(&var->img, x, y, color);
			x++;
		}
		y--;
	}
}

void	render_floor_ceiling(t_vars *var, t_config *config)
{
	int	y;

	y = WINDOW_HEIGHT / 2;
	render_floor(var, y, config->floor);
	render_ceiling(var, y, config->ceiling);
}