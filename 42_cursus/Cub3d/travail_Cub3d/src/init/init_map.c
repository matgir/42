/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <itahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 19:46:51 by itahani           #+#    #+#             */
/*   Updated: 2024/01/17 16:13:32 by itahani          ###   ########.fr       */
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
	var->mapwidth = var->win.width;
	var->mapheight = var->win.height;
}

/*------ définition window, img à composer et à afficher -------*/
void	def_var(t_vars *var)
{
	get_win_size(var);
	var->win.win = mlx_new_window(var->mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT, "Minimap - itahani & mgirardo");
	var->img.img = mlx_new_image(var->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	var->img.addr = mlx_get_data_addr(var->img.img,
			&var->img.bpp, &var->img.ll, &var->img.e);
	var->scale_minimap = 0.08;
	while (var->mapheight * var->scale_minimap > WINDOW_HEIGHT * 0.2
		|| var->mapwidth * var->scale_minimap > WINDOW_WIDTH * 0.2)
		var->scale_minimap -= 0.001;
	init_config(&var->config);
	init_textures(var);
	init_player(&var->player, var);
	init_rays(var);
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

char	**get_map(t_vars *var, char **file)
{
	int		i;
	char	*to_free;
	char	*valeur;
	char	**map;

	i = parsing_elements(var, file);
	if (i == 0)
		return (free(var->config.tab), NULL);
	if (i == 1)
		return (NULL);
	valeur = ft_strdup("");
	while (file[++i])
		if (file[i][0] != '\n')
			break ;
	while (file[i] != NULL)
	{
		to_free = valeur;
		if (file[i][0] == '\n')
			return (free(valeur), free_tab(var->config.tab), NULL);
		valeur = ft_strjoin(valeur, file[i++]);
		if (to_free)
			free(to_free);
	}
	map = ft_split(valeur, '\n');
	return (free(valeur), map);
}
