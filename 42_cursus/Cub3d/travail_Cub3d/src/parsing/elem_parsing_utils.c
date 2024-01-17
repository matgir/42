/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem_parsing_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <itahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 00:49:44 by itahani           #+#    #+#             */
/*   Updated: 2024/01/17 15:02:03 by itahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/*-------- clairement juste de la norme --------*/
void	set_valid_value(char **file, int *i, int *valid)
{
	if (is_only_whitespace(file[*i]) == 0)
			*i += 1;
	while (file[*i][0] == '\n')
		*i += 1;
	*valid = is_valid_element(file[*i]);
}

/*------ valeur de retour set à 1 pour quitter fonction récursive -------*/
void	ret_to_one(int *ret)
{
	*ret = 1;
}

/*------	compare élément valide avec les autres 
			pour check les doublons		-------*/
int	check_doublons(char **tab, char *elem)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		if (ft_strncmp(tab[i], elem, 1) == 0)
			return (1);
		i++;
	}
	return (0);
}

/*------ check si index rvb valide (de 0 à 255) -------*/
int	valid_rgb_index(char *element, int *i)
{
	char	*nb;
	int		j;
	int		color;

	j = 0;
	nb = malloc(sizeof(char) * ft_strlen(element));
	if (!nb)
		return (1);
	while (element[*i] == ' ')
		*i += 1;
	while (element[*i] >= 48 && element[*i] <= 57)
	{
		nb[j++] = element[*i];
		*i += 1;
	}
	nb[j] = '\0';
	color = ft_atoi(nb);
	if (ft_strlen(nb) > 3 || ft_strlen(nb) == 0
		|| color < 0 || color > 255)
		return (free(nb), 1);
	while (element[*i] == ' ')
		*i += 1;
	return (free(nb), 0);
}

/*------ récupère le chemin vers le fichier texture -------*/
char	*get_path_texture(char *element)
{
	int		i;
	int		j;
	char	*path;

	i = 3;
	j = 0;
	while (element[i] && element[i] != '\n'
		&& element[i] == ' ')
		i++;
	j = i;
	while (element[j] && element[j] != '\n')
		j++;
	path = malloc(sizeof(char) * (j + 1));
	j = 0;
	while (element[i] && element[i] != '\n')
		path[j++] = element[i++];
	path[j] = '\0';
	return (path);
}
