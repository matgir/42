/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <itahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 17:23:03 by itahani           #+#    #+#             */
/*   Updated: 2023/11/07 21:34:25 by itahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	nb_lignes(const char *str)
{
	int	i;
	int	nb;

	nb = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			nb++;
		i++;
	}
	return (nb);
}

static int	ft_wordlen(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		i++;
	}
	if (s[i] == c)
		i++;
	return (i);
}

static void	*ft_free_tab(char **str_arr)
{
	int	i;

	i = -1;
	while (str_arr[++i])
		free(str_arr[i]);
	free(str_arr);
	return (NULL);
}

char	**split_for_cub(const char *s, char c)
{
	int		i;
	int		n;
	char	**str_arr;

	if (!s)
		return (NULL);
	str_arr = malloc(sizeof(char *) * (nb_lignes(s) + 2));
	if (!str_arr)
		return (NULL);
	i = 0;
	while (*s)
	{
		n = ft_wordlen(s, c);
		str_arr[i++] = ft_substr(s, 0, n);
		if (!str_arr[i - 1])
			return (ft_free_tab(str_arr));
		s += n;
	}
	str_arr[i] = NULL;
	return (str_arr);
}
