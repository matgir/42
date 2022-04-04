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

#include "libfdf.h"

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

char	***ft_parsing(char *map_b_parsing, int *y, int *x)
{
	char	*line;
	int		fd;
	char	***z_coordinates;
	int		i;
	int		x_tmp;

	*y = find_y(map_b_parsing);
	z_coordinates = malloc(sizeof(char **) * (*y + 1));
	if (z_coordinates == NULL)
		return(NULL);
	fd = open(map_b_parsing, O_RDONLY);
	i = 0;
	*x = 0;
	x_tmp = *x;
	line = get_next_line(fd);
	if (line == NULL)
		return (z_coordinates);
	z_coordinates[i++] = ft_fdf_split(line, ' ', x);
	x_tmp = *x;
	while(1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (z_coordinates);
		z_coordinates[i++] = ft_fdf_split(line, ' ', x);
		if (x_tmp != *x)
			return (NULL); // free z_coordinates pour etre clean
		x_tmp = *x;
	}
	return(z_coordinates);
}

int	main(int ac, char **av)
{
	char	***z_coordinates;
	int		y;
	int		x;

	if (ac != 2)
	{
		ft_printf("no maps"); // faire meilleur message
		return(1);
	}
	else
	{
		z_coordinates = ft_parsing(av[1], &y, &x);
		if (z_coordinates == NULL)
			return(ft_printf("bad map")); // faire meilleur message
	}
	ft_printf("x = %i\ny = %i", x, y);
	return(0);
}
