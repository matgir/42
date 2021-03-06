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

#include "libft.h"

static int	dbt(char const *s, char c)
{
	size_t	stop;

	stop = 0;
	while (s[stop] && s[stop] == c)
		stop++;
	return (stop);
}

/*		permet de trouver ou se trouve le 1er mot		*/

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

/*		permet de compter le nombre de mots		*/

static char	**free_all(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		free(tab[i++]);
	free(tab);
	return (NULL);
}

/*		permet de free la partie du tableau deja creer en cas d'echec
 *		d'allocation pour un nouveau mot		*/

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
