/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <itahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 23:07:58 by itahani           #+#    #+#             */
/*   Updated: 2023/11/07 21:34:25 by itahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	parsing(t_vars *var)
{
	if (wall_surrounded(var->map) == 1)
		return (ft_putstr_fd("Error: Invalid file content\n", 2), 1);
	if (one_player(var->map) == 1)
		return (1);
	if (allowed_char(var->map) == 1)
		return (ft_putstr_fd("Error: character non allowed in map\n", 2), 1);
	return (0);
}
