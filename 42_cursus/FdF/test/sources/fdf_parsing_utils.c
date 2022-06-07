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
	int	line_count;
	int	fd;
	int	useless;
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
		perror("The map you choose cannot be read, please select another");
	if (gnl_error == -2)
		ft_putendl_fd("There was an error during the allocation of the memory, please try again", 1);
	if (gnl_error == -3)
		ft_putendl_fd("Cannot parse file, please select another",1);
	return(NULL);
}

int	coord_current_lines(int **coord)
{
	int	i;

	i = 0;
	while (coord[i] != NULL)
		i++;
	return (i);
}