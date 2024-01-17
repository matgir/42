/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <itahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 19:32:38 by itahani           #+#    #+#             */
/*   Updated: 2024/01/17 14:56:03 by itahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/*------ render minimap -------*/
void	render_minimap(t_vars *var)
{
	composer_map(var);
}

/*------ render map 3d -------*/
void	render_3d_map(t_vars *var)
{
	render_floor_ceiling(var, &var->config);
	render_walls(var);
}
