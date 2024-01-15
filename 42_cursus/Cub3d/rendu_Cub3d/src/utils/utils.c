/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <itahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 20:05:11 by itahani           #+#    #+#             */
/*   Updated: 2023/11/08 15:13:59 by itahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	print_error(char *err)
{
	char *msg;

	msg = ft_strjoin("Error: ", err);
	ft_putstr_fd(msg, 2);
	free(msg);
}

int	ft_height(char **map)
{
	int	x;

	x = 0;
	while (map[x])
		x++;
	return (x);
}

int	tab_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

char	**ft_trim_tab(char **tab)
{
	int		i;
	char	**res;

	i = 0 ;
	res = malloc(sizeof(char *) * 7);
	while (tab[i])
	{
		res[i] = ft_strtrim(tab[i], "\n");
		i++;
	}
	res[i] = '\0';
	return (res);
}

/*------ return 0 si que du whitespace et 1 si autre contenu -------*/
int	is_only_whitespace(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if ((line[i] == 32) || (line[i] >= 9 && line[i] <= 13))
			i++;
		else
			return (1);
	}
	return (0);
}
