/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <itahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 19:46:51 by itahani           #+#    #+#             */
/*   Updated: 2024/01/14 21:54:18 by itahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	get_win_size(t_vars *var)
{
	int	x;

	var->win.height = 0;
	var->win.width = 0;
	while (var->map[var->win.height])
	{
		x = 0;
		while (var->map[var->win.height][x])
			x++;
		var->win.height += 1;
		if (var->win.width < x)
			var->win.width = x;
	}
	var->win.width *= TILE_SIZE;
	var->win.height *= TILE_SIZE;
	var->mapWidth = var->win.width;
	var->mapHeight = var->win.height;
}

/*------ définition window, img à composer et à afficher -------*/
void	def_var(t_vars *var)
{
	get_win_size(var); //SUPPRIMER
	var->win.win = mlx_new_window(var->mlx, WINDOW_WIDTH, \
		WINDOW_HEIGHT, "Minimap - itahani & mgirardo");
	var->img.img = mlx_new_image(var->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	var->img.addr = mlx_get_data_addr(var->img.img, \
		&var->img.bits_per_pixel, &var->img.line_length, &var->img.endian);
	init_config(&var->config);
	init_textures(var);
	init_player(&var->player, var);
	cast_all_rays(var);
	render_3d_map(var);
	render_minimap(var);
}

/*------ passer data du infile.cub a un char ** -------*/
char	**cub_to_tab(int fd)
{
	char	*lecture;
	char	*valeur;
	char	**tab;
	char	*to_free;

	valeur = ft_strdup("");
	lecture = NULL;
	lecture = get_next_line(fd);
	while (lecture != NULL)
	{
		to_free = valeur;
		valeur = ft_strjoin(valeur, lecture);
		if (to_free)
			free(to_free);
		free(lecture);
		lecture = get_next_line(fd);
	}
	free(lecture);
	tab = split_for_cub(valeur, '\n');
	free(valeur);
	return (tab);
}

/*------ extraction de la map dans infile.cub a un char ** -------*/
char	**get_map(t_vars *var, char **file)
{
	int		i;
	char	*to_free;
	char	*valeur;
	char	**map;

	i = parsing_elements(var, file);
	if (i == 1)
		return (ft_putstr_fd("Error: Invalid input\n", 2), NULL);
	valeur = ft_strdup("");
	i += 1;
	while (file[i] != NULL)
	{
		to_free = valeur;
		valeur = ft_strjoin(valeur, file[i]);
		if (to_free)
			free(to_free);
		i++;
	}
	map = ft_split(valeur, '\n');
	free(valeur);
	return (map);
}
