/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <itahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 19:32:38 by itahani           #+#    #+#             */
/*   Updated: 2024/01/13 18:34:17 by itahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/*------ render minimap -------*/
void	render_minimap(t_vars *var)
{
	composer_map(var);
	show_player_on_minimap(&var->player, var);
	vision_line(&var->img, &var->player, 0xda0722);
	render_FOV(var, &var->player, 0x00FF00);
}


/*------ render map 3d -------*/
void	render_3d_map(t_vars *var)
{
	render_floor_ceiling(var, &var->config);
	render_walls(var);
}
