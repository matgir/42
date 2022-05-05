/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:38:59 by mgirardo          #+#    #+#             */
/*   Updated: 2022/05/02 16:28:06 by mgirardo         ###   ########.fr       */
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
	float	nbs_w = (x - 1 + y - 1)/2;
	float	nbs_h = (((float)x - 1 + (float)y - 1)/4);
	float	w_diag = 1536/nbs_w;
	float	h_diag= 768/nbs_w;
	printf("nbs_w = %f\nnbs_h = %f\n", nbs_w, nbs_h);
	printf("w_diag = %f\nh_diag = %f\n", w_diag, h_diag);
	ft_printf("x = %i\ny = %i\n", x, y);
	printf("coord first point = (%f;%d)\n", (192 + (w_diag * (((float)y - 1) / 2))), 96);
	ft_printf("%s\n", z_coordinates[0][0]);


	t_coord	**coo;

	coo = malloc(sizeof(t_coord *) * (y));
	if (coo == NULL)
		return (ft_printf("Malloc error"));
	int	i = 0;
	while (i < y)
	{
		coo[i] = malloc(sizeof(t_coord *) * (x));
		if (coo[i] == NULL)
			return (ft_printf("Malloc error"));
		i++;
	}
	i = 0;
	int j = 0;
	coo[i][j].x_axe = (192 + (w_diag * (((float)y - 1) / 2 )));
	coo[i][j].y_axe = 96;
	printf("coord %i,%i = (%f;%f)\n", i, j, coo[i][j].x_axe, coo[i][j].y_axe);

	//printf("w_diag = %f\nh_diag = %f\n", w_diag, h_diag);
	while (++j < x)
	{
		coo[i][j].x_axe = coo[i][j - 1].x_axe + (w_diag / 2);
		coo[i][j].y_axe = coo[i][j - 1].y_axe + (h_diag / 2);
		//printf("coord %i,%i = (%d;%d)\n", i, j, coo[i][j].x_axe, coo[i][j].y_axe);
		//printf("coord %i,%i = (%s)\n", i, j, z_coordinates[i][j]);
	}
	while (++i < y)
	{
		j = 0;
		coo[i][j].x_axe = coo[i - 1][j].x_axe - w_diag / 2;
		coo[i][j].y_axe = coo[i - 1][j].y_axe + h_diag / 2;
		//printf("jour coord %i,%i = (%d;%d)\n", i, j, coo[i][j].x_axe, coo[i][j].y_axe);
		//printf("coord %i,%i = (%s)\n", i, j, z_coordinates[i][j]);
		while (++j < x)
		{
			coo[i][j].x_axe = coo[i][j - 1].x_axe + (w_diag / 2);
			coo[i][j].y_axe = coo[i][j - 1].y_axe + (h_diag / 2);
			//printf("rouj coord %i,%i = (%d;%d)\n", i, j, coo[i][j].x_axe, coo[i][j].y_axe);
			//printf("coord %i,%i = (%s)\n", i, j, z_coordinates[i][j]);
		}
	}
	coo = incorporate_z(coo, z_coordinates, x, y);
	window(x, y, coo);
	return (0);
}
