/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <itahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 21:26:39 by itahani           #+#    #+#             */
/*   Updated: 2023/11/07 21:34:25 by itahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	wall_surrounded_loop(char **map, int x, int y, int y_max)
{
	int	x_max;

	x_max = ft_height(map);
	if (((x == 0 && map[x][y] != ' ') || (x > 0 && (map[x - 1]
				&& (size_t)y <= ft_strlen(map[x - 1]) && map[x - 1][y])
		&& map[x - 1][y] == ' ' && map[x][y] && map[x][y] != ' '))
		&& (map[x][y] != '1'))
		return (1);
	if (((x == x_max - 1 && map[x][y] != ' ') || (x < x_max && (map[x + 1]
				&& (size_t)y <= ft_strlen(map[x + 1]) && map[x + 1][y])
		&& map[x + 1][y] == ' ' && map[x][y] && map[x][y] != ' '))
		&& (map[x][y] != '1'))
		return (1);
	if (((y == 0 && map[x][y] != ' ') || (y > 0 && map[x][y - 1] && map[x][y
		- 1] == ' ' && map[x][y] && map[x][y] != ' '))
		&& (map[x][y] != '1'))
		return (1);
	if (((y == y_max - 1 && map[x][y] != ' ') || (y < y_max && map[x][y + 1]
		&& map[x][y + 1] == ' ' && map[x][y] && map[x][y] != ' '))
		&& (map[x][y] != '1'))
		return (1);
	return (x + 1 < x_max && map[x][y] != ' ' && map[x][y] != '1'
		&& (size_t)y >= ft_strlen(map[x + 1]));
}

int	wall_surrounded(char **map)
{
	int	x;
	int	y;
	int	y_max;

	x = 0;
	while (map[x])
	{
		y = 0;
		y_max = ft_strlen(map[x]);
		while (map[x][y])
		{
			if (wall_surrounded_loop(map, x, y, y_max) == 1)
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}
