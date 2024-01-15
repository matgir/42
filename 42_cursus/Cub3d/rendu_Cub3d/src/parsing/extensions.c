/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extensions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <itahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 18:14:16 by itahani           #+#    #+#             */
/*   Updated: 2023/11/07 21:34:25 by itahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/*------ vérification de l'extension .cub ------*/
int	check_extension(char *filename)
{
	int	i;

	i = ft_strlen(filename) - 1;
	if (filename[i] != 'b' || filename[i - 1] != 'u'
		|| filename[i - 2] != 'c' || filename[i - 3] != '.')
		return (1);
	return (0);
}

/*------ vérification de l'extension .xpm ------*/
int	check_xpm(char *path)
{
	int	i;

	i = ft_strlen(path) - 1;
	if (path[i] != 'm' || path[i - 1] != 'p'
		|| path[i - 2] != 'x' || path[i - 3] != '.')
		return (1);
	return (0);
}
