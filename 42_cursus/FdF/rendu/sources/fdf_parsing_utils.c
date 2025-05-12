/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:26:37 by mgirardo          #+#    #+#             */
/*   Updated: 2022/06/07 17:26:43 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

int	count_lines(char *z_map)
{
	int		line_count;
	int		fd;
	int		useless;
	char	*line;

	fd = open(z_map, O_RDONLY);
	line_count = 0;
	line = fdf_gnl(fd, &useless);
	while (line != NULL)
	{
		line_count++;
		free(line);
		line = fdf_gnl(fd, &useless);
	}
	close(fd);
	return (line_count);
}

int	**specifie_error(int **coord, int gnl_error)
{
	int	i;

	i = -1;
	if (coord != NULL)
	{
		while (coord[++i] != NULL)
			free(coord[i]);
		free(coord);
	}
	if (gnl_error == -1)
		ft_putendl_fd("The chosen map can't be read, please select another", 1);
	if (gnl_error == -2)
		ft_putendl_fd("Allocation failure, please try again", 1);
	if (gnl_error == -3)
		ft_putendl_fd("Cannot parse file, please select another", 1);
	return (NULL);
}

int	coord_current_lines(int **coord)
{
	int	i;

	i = 0;
	while (coord[i] != NULL)
		i++;
	return (i);
}

int	first_check(int *line_count, char *z_map, int *fd)
{
	*fd = open(z_map, __O_DIRECTORY);
	if (*fd > 0)
	{
		ft_putendl_fd("This is a directory, please select a valid map", 1);
		return (-1);
	}
	*fd = open(z_map, O_RDONLY);
	if (*fd == -1)
	{
		ft_putendl_fd("The chosen map can't be read, please select another", 1);
		return (-1);
	}
	*line_count = count_lines(z_map);
	if (*line_count == 0)
	{
		ft_putendl_fd("Nothing to render, please select another map", 1);
		return (-1);
	}
	return (0);
}

int	malloc_check(char *line, int **coord, int *gnl_error)
{
	if (line == NULL)
	{
		if (*gnl_error < 0)
		{
			specifie_error(coord, *gnl_error);
			return (-1);
		}
	}
	return (0);
}
