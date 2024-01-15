/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <itahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 17:38:38 by itahani           #+#    #+#             */
/*   Updated: 2024/01/14 22:25:06 by itahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/*-------- a mettre dans utils ----------*/
char	*dup_trim(char **elm, int i)
{
	char	*tmp;
	char	*res;
	int		j;
	int		n;

	n = 0;
	j = 2;
	tmp = ft_strdup(elm[i]);
	res = malloc(sizeof(char) * ft_strlen(tmp));
	while (tmp[j] == ' ')
		j++;
	while (tmp[j] && tmp[j] != ' ')
		res[n++] = tmp[j++];
	res[n] = '\0';
	free(tmp);
	return (res);
}

void	init_config_text(t_config *config, char **elm, int i)
{
	if (elm[i][0] == 'N')
		config->north = dup_trim(elm, i);
	else if (elm[i][0] == 'S')
		config->south = dup_trim(elm, i);
	else if (elm[i][0] == 'E')
		config->east = dup_trim(elm, i);
	else if (elm[i][0] == 'W')
		config->west = dup_trim(elm, i);
}

/*------ initialisation struct pour rendering -------*/
void	init_config(t_config *config)
{
	int		i;
	char	**elm;
	char	*floor;
	char	*ceiling;

	i = 0;
	elm = ft_trim_tab(config->tab);
	while (config->tab[i])
	{
		if (elm[i][0] == 'N' || elm[i][0] == 'S'
			|| elm[i][0] == 'E' || elm[i][0] == 'W')
			init_config_text(config, elm, i);
		else if (elm[i][0] == 'F')
		{
			floor = ft_strdup(elm[i]);
			get_hexa(floor, &config->floor);
		}
		else if (elm[i][0] == 'C')
		{
			ceiling = ft_strdup(elm[i]);
			get_hexa(ceiling, &config->ceiling);
		}
		i++;
	}
	free_tab(elm);
}

void	get_rgb(t_color	*color)
{
	int		i;

	i = 0;
	color->r = malloc(sizeof(char) * 4);
	color->g = malloc(sizeof(char) * 4);
	color->b = malloc(sizeof(char) * 4);
	while (color->rgb[i] && (color->rgb[i] < '0' || color->rgb[i] > '9'))
		i++;
	get_color(color->rgb, color->r, &i);
	while (color->rgb[i] && (color->rgb[i] < '0' || color->rgb[i] > '9'))
		i++;
	get_color(color->rgb, color->g, &i);
	while (color->rgb[i] && (color->rgb[i] < '0' || color->rgb[i] > '9'))
		i++;
	get_color(color->rgb, color->b, &i);
}

void	get_hexa(char *tmp_rgb, int *rgb)
{
	t_color	color;
	char	*hexa;

	color.rgb = ft_strdup(tmp_rgb);
	free(tmp_rgb);
	get_rgb(&color);
	color.r_hexa = get_hexa_color(color.r);
	color.g_hexa = get_hexa_color(color.g);
	color.b_hexa = get_hexa_color(color.b);
	hexa = malloc(sizeof(char) * 9);
	ft_strjoin_hexa(hexa, &color);
	hexa_str_to_int(&color, rgb);
	free(color.rgb);
	free(color.r_hexa);
	free(color.g_hexa);
	free(color.b_hexa);
	free(color.hexa);
}
