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

/*		permet de trouver ou se trouve le 1er mot		*/

int	nw(char *s, size_t stop)
{
	size_t	nbw;

	nbw = 0;
	while (s[stop])
	{
		if (s[stop] != 32 && (s[stop + 1] == 32 || s[stop + 1] == '\0'))
			nbw += 1;
		stop++;
	}
	return (nbw);
}

/*		permet de compter le nombre de mots		*/

char	**free_all(char **tab)
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

char	**ft_fdf_split(char *s, int *x)
{
	char	**tab;
	int		i;
	int		start;
	int		stop;

	if (s[0] != '\n')
		s[ft_strlen(s) - 1] = '\0';
	else
	{
		*x = 0;
		return (NULL);
	}
	tab = malloc(sizeof(char *) * ((*x = nw(s, (stop = dbt(s))))));
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
