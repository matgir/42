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

int	parsing(t_vars *var, int fd)
{
	int	i;

	if (wall_surrounded(var->map) == 1)
		return (close(fd), free_for_parser(var), ft_exit("Invalid file content\n"));
		// return (ft_putstr_fd("Error: Invalid file content\n", 2), 1);
	i = one_player(var->map);
	if (i == 1)
		return (close(fd), free_for_parser(var), ft_exit("Needing a player\n"));
	else if (i == 2)
		return (close(fd), free_for_parser(var), ft_exit("Only one player required\n"));
	if (allowed_char(var->map) == 1)
		return (close(fd), free_for_parser(var), ft_exit("Unauthorized charater\n"));
		// return (ft_putstr_fd("Error: Invalid character in map\n", 2), 1);
	return (0);
}
