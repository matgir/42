/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:20:41 by mgirardo          #+#    #+#             */
/*   Updated: 2022/06/07 17:20:46 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

int	**add_coord(int **coord)
{
	int	**new_coord;
	int	i;

	if (coord == NULL)
	{
		coord = malloc(sizeof(*coord));
		if (coord == NULL)
			return (NULL);
		coord[0] = NULL;
	}
	new_coord = malloc(sizeof(*coord) * (coord_current_lines(coord) + 2));
	if (new_coord == NULL)
		return (NULL);
	i = -1;
	while (++i < coord_current_lines(coord))
		new_coord[i] = coord[i];
	new_coord[i++] = NULL;
	new_coord[i] = NULL;
	free(coord);
	return (new_coord);
}

int	*get_int(char *line, int *column_count)
{
	char	**split;
	int		*get_int;
	int		column;
	int		i;

	split = ft_split(line, ' ');
	if (split == NULL)
		return (NULL);
	column = 0;
	while (split[column] != NULL)
		column++;
	get_int = malloc(sizeof(int) * column);
	if (get_int)
	{
		i = -1;
		while (++i < column)
			get_int[i] = ft_atoi(split[i]);
		*column_count = i;
	}
	column = -1;
	while (split[++column] != NULL)
		free(split[column]);
	free(split);
	return (get_int);
}

int	**add_line(char *line, int **coord, int *column_count)
{
	int	*pre_line;

	coord = add_coord(coord);
	if (coord == NULL)
		return (NULL);
	pre_line = get_int(line, column_count);
	if (pre_line == NULL)
		return (NULL);
	if (coord_current_lines(coord) == 0)
		coord[0] = pre_line;
	else
		coord[coord_current_lines(coord)] = pre_line;
	return (coord);
}

int	**ft_parsing(int fd, int *column_count, int *line_count)
{
	char	*line;
	int		gnl_error;
	int		**coord;
	int		i;
	int		col_tmp;

	coord = NULL;
	gnl_error = 0;
	i = -1;
	col_tmp = -1;
	while (++i < *line_count)
	{
		line = fdf_gnl(fd, &gnl_error);
		if (malloc_check(line, coord, &gnl_error) == -1)
			return (NULL);
		coord = add_line(line, coord, column_count);
		if (coord == NULL || (col_tmp != -1 && col_tmp != *column_count))
		{
			free(line);
			return (specifie_error(coord, -3));
		}
		col_tmp = *column_count;
		free(line);
	}
	return (coord);
}

t_coord	*parse_map(char *z_map)
{
	int		fd;
	int		**z_coord;
	int		column_count;
	int		line_count;
	t_coord	*coord;

	if (first_check(&line_count, z_map, &fd) == -1)
		return (NULL);
	z_coord = ft_parsing(fd, &column_count, &line_count);
	if (z_coord == NULL)
		return (NULL);
	coord = malloc(sizeof(t_coord));
	if (coord == NULL)
		return (NULL);
	coord->coord = z_coord;
	coord->line_count = line_count;
	coord->column_count = column_count;
	close(fd);
	return (coord);
}
