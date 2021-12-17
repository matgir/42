/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 09:47:53 by mgirardo          #+#    #+#             */
/*   Updated: 2021/12/17 17:04:36 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stddef.h>

static int	dbt(char const *s, char c)
{
	size_t	stop;

	stop = 0;
	while (s[stop] && s[stop] == c)
		stop++;
	return (stop);
}

static int	nw(char const *s, char c, size_t stop)
{
	size_t	nbw;

	nbw = 0;
	while (s[stop])
	{
		while (s[stop] && s[stop] != c)
			stop++;
		nbw++;
		while (s[stop] && s[stop] == c)
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

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		start;
	int		stop;
	int		nbw;

	tab = malloc(sizeof(char *) * ((nbw = nw(s, c, (stop = dbt(s, c)))) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (s[stop])
	{
		start = stop;
		while (s[stop] != c && s[stop])
			stop++;
		tab[i] = ft_substr(s, start, stop - start);
		if (tab[i++] == NULL)
			return (free_all(tab));
		while (s[stop] == c && s[stop])
			stop++;
	}
	tab[i] = 0;
	return (tab);
}
