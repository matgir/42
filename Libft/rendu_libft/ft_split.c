/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 09:47:53 by mgirardo          #+#    #+#             */
/*   Updated: 2021/12/17 14:09:21 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stddef.h>

static size_t	dbt(char const *s, char c)
{
	size_t	stop;

	stop = 0;
	while (s[stop] && s[stop] == c)
		stop++;
	return (stop);
}

static size_t	nw(char const *s, char c, size_t stop)
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

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	start;
	size_t	stop;
	size_t	nbw;

	tab = malloc(sizeof(*tab) * ((nbw = nw(s, c, (stop = dbt(s, c)))) + 1));
	if (s == NULL || stop == ft_strlen(s) || tab == NULL)
		return (tab = NULL);
	i = 0;
	while (s[stop] && i < nbw)
	{
		start = stop;
		while (s[stop] != c && s[stop])
			stop++;
		tab[i] = ft_substr(s, start, stop - start);
		if (tab[i++] == NULL)
		{
			free(tab);
			return (NULL);
		}
		while (s[stop] == c && s[stop])
			stop++;
	}
	tab[nbw + 1] = 0;
	return (tab);
}
