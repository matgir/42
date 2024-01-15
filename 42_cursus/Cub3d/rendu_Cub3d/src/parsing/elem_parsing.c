/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <itahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:42:44 by itahani           #+#    #+#             */
/*   Updated: 2023/11/08 15:14:13 by itahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/*------ est-ce que color code est valide -------*/
int	is_color_code(char *element, int i)
{
	static int	count = 0;
	static int	ret = 0;

	if (valid_rgb_index(element, &i) == 1)
		return (ret_to_one(&ret), 1);
	if (element[i] == ',')
	{
		count++;
		is_color_code(element, i + 1);
	}
	else if (element[i] == '\n')
	{
		count++;
		if (count != 3)
			return (ret_to_one(&ret), 1);
		count = 0;
	}
	else if (element[i] != '\n')
		return (ret_to_one(&ret), 1);
	if (ret == 1)
		return (ret_to_one(&ret), 1);
	return (0);
}

/*------ vérification de l'identifier (1 ou 2 lettres) -------*/
int	is_identifier(char *element)
{
	if (ft_strlen(element) < 3)
		return (1);
	if ((element[0] == 'N' && element[1] == 'O' && element[2] == ' ')
		|| (element[0] == 'S' && element[1] == 'O' && element[2] == ' ')
		|| (element[0] == 'W' && element[1] == 'E' && element[2] == ' ')
		|| (element[0] == 'E' && element[1] == 'A' && element[2] == ' '))
		return (2);
	else if ((element[0] == 'F' && element[1] == ' ')
		|| (element[0] == 'C' && element[1] == ' '))
		return (0);
	return (1);
}

/*------ est-ce que l'élément complet est valide -------*/
int	is_valid_element(char *element)
{
	char	*path_texture;
	int		id_ret;

	path_texture = NULL;
	id_ret = is_identifier(element);
	if (id_ret == 2)
	{
		path_texture = get_path_texture(element);
		if (check_xpm(path_texture) == 1
			|| access(path_texture, R_OK) != 0)
			return (free(path_texture), 1); // invalid input: wrong path
	}
	else if (id_ret == 0)
	{
		if (is_color_code(element, 1) == 1)
			return (1); // invalid input: wrong color code
	}
	else if (id_ret == 1)
		return (1);
	return (free(path_texture), 0);
}

/*------ ajoute l'élément valide au tableau, return 1 si doublons -------*/
int	add_element(char *element, t_vars *var)
{
	static int	i = 0;

	if (check_doublons(var->config.tab, element) == 1) //invalid input: doublons
		return (free_tab(var->config.tab), 1);
	var->config.tab[i] = ft_strdup(element);
	i += 1;
	var->config.tab[i] = NULL;
	return (0);
}

int	parsing_elements(t_vars *var, char **file)
{
	int		i;
	int		valid;

	i = 0;
	var->config.tab = malloc(sizeof(char *) * 7);
	if (!var->config.tab)
		return (1);
	var->config.tab[0] = NULL;
	while (file[i])
	{
		set_valid_value(file, &i, &valid);
		if (valid == 0)
		{
			if (add_element(file[i], var) == 1)
				return (1);
			if (tab_len(var->config.tab) == 6)
				break ;
		}
		else if (valid == 1)
			return (free_tab(var->config.tab), 1);
		i++;
	}
	return (i); /*	return l'index de la ligne a partir de laquelle on a fini de
					parser les elements, pour commencer a parser la map */
}
