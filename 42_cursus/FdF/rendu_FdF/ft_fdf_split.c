/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 09:47:53 by mgirardo          #+#    #+#             */
/*   Updated: 2022/01/04 16:37:27 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

int	dbt(char *s)
{
	size_t	stop;

	stop = 0;
	while (s[stop] && s[stop] == 32)
		stop++;
	return (stop);
}

int	nw(char *s, size_t stop)
{
	size_t	nbw;

	nbw = 0;
	while (s[stop])
	{
		while (s[stop] && s[stop] != 32)
			stop++;
		nbw++;
		while (s[stop] && s[stop] == 32)
			stop++;
	}
	return (nbw);
}

char	**free_all(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		free(tab[i++]);
	free(tab);
	return (NULL);
}

char	**ft_fdf_split(char *s, int *x)
{
	char	**tab;
	int		i;
	int		start;
	int		stop;

	tab = malloc(sizeof(char *) * ((*x = nw(s, (stop = dbt(s)))) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (s[stop])
	{
		start = stop;
		while (s[stop] != 32 && s[stop])
			stop++;
		tab[i] = ft_substr(s, start, stop - start);
		if (tab[i++] == NULL)
			return (free_all(tab));
		while (s[stop] == 32 && s[stop])
			stop++;
	}
	tab[i] = 0;
	return (tab);
}