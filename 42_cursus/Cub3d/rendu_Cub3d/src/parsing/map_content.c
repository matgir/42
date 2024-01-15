/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <itahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:20:28 by itahani           #+#    #+#             */
/*   Updated: 2023/11/07 21:34:25 by itahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	is_player(char c)
{
	if (c == 'N' || c == 'S'
		|| c == 'E' || c == 'W' )
		return (0);
	return (1);
}

int	one_player(char **map)
{
	int	x;
	int	y;
	int	p;

	x = -1;
	p = 0;
	while (map[++x])
	{
		y = -1;
		while (map[x][++y])
		{
			if (is_player(map[x][y]) == 0)
				p++;
		}
	}
	if (p == 0)
		return (ft_putstr_fd("Error: needing a player\n", 2), 1);
	if (p > 1)
		return (ft_putstr_fd("Error: only one player required\n", 2), 1);
	return (0);
}

int	allowed_char(char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] != ' ' && map[x][y] != 'N'
				&& map[x][y] != 'S' && map[x][y] != 'E'
				&& map[x][y] != 'W' && map[x][y] != '1'
				&& map[x][y] != '0')
				return (1);
			y++;
		}
		x++;
	}
	return (0);
}
