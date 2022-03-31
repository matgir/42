/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:38:59 by mgirardo          #+#    #+#             */
/*   Updated: 2022/03/31 16:39:02 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libFdF.h"

int		find_y(char *map)
{
	int		fd;
	int		y;

	fd = open(map, O_RDONLY);
	y = 0;
	while(get_next_line(fd) != NULL)
		y++;
	return(y);
}

char	***ft_parsing(char *map_b_parsing)
{
	char	*line;
	int		y;
	int		fd;
	char	***map;

	line = "0"
	y = find_y(char *map_b_parsing);
	map = malloc(sizeof(char **) * ((nbw = y + 1));
	if (map == NULL)
		return(NULL);
	map[y + 1] = "\0";
	while(line != NULL)
	{
		fd = open(map_b_parsing, O_RDONLY);
		line = get_next_line(fd);
	}
}

int	main(int ac, char **map_b_parsing)
{
	char	***map;

	if (ac <= 1)
	{
		ft_printf("no maps");
		return(1);
	}
	else
	{
		map = ft_parsing(map_b_parsing[1]);
		if (map == NULL);
			return(NULL);
	}
}
