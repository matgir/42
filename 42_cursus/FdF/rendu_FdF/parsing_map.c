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

int	find_y(char *map)
{
	int		fd;
	int		y;

	fd = open(map, O_RDONLY);
	y = 0;
	while (fdf_get_next_line(fd) != NULL)
		y++;
	return (y);
}

char	***free_z(char ***z)
{
	int	i;
	int	j;

	i = 0;
	while (z[i] != NULL)
	{
		j = 0;
		while (z[i][j] != NULL)
		{
			free(z[i][j]);
			j++;
		}
		free(z[i]);
		i++;
	}
	free(z);
	return (NULL);
}

char	***ft_store_z(char ***z_coordinates, int fd, int *x)
{
	char	*line;
	int		i;
	int		x_tmp;

	i = 0;
	*x = 0;
	x_tmp = -1;
	while (1)
	{
		line = fdf_get_next_line(fd);
		if (line == NULL)
			return (z_coordinates); //je dois faire quoi si mon malloc echou ?
		z_coordinates[i] = ft_fdf_split(line, x);
		if (z_coordinates[i] == NULL || (x_tmp != -1 && x_tmp != *x))
		{
			free_z(z_coordinates);
			return (NULL);
		}
		x_tmp = *x;
		i++;
	}
}

char	***ft_parsing(char *map_b_parsing, int *y, int *x)
{
	int		fd;
	char	***z_coordinates;

	*y = find_y(map_b_parsing);
	z_coordinates = malloc(sizeof(char **) * (*y));
	if (z_coordinates == NULL)
		return (NULL);
	fd = open(map_b_parsing, O_RDONLY);
	z_coordinates = ft_store_z(z_coordinates, fd, x);
	close(fd);
	return (z_coordinates);
}

int	main(int ac, char **av)
{
	char	***z_coordinates;
	int		y;
	int		x;

	if (ac != 2)
		return (ft_printf("Please select one map to render"));
	z_coordinates = ft_parsing(av[1], &y, &x);
	if (z_coordinates == NULL)
		return (ft_printf("The map is invalide, choose another"));
	printf("height = %f\n", sqrt((pow(y, 2)/(hypot(x, y))) * (pow(x, 2)/(hypot(x, y)))));
	ft_printf("x = %i\ny = %i", x, y);
	return (0);
}
