/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:21:07 by mgirardo          #+#    #+#             */
/*   Updated: 2022/01/04 16:43:52 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_chr(char const *set, char c, size_t lenset)
{
	size_t	i;

	i = 0;
	while (i <= lenset)
	{
		if (set[i] == c)
			return (0);
		i++;
	}
	return (1);
}

/*		permet de se deplacer tant que le caractere fait parti
 *		du set aue l'on veut retirer en debut et en fin		*/

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		stop;
	char	*strtrim;
	size_t	lenset;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return ((char *)s1);
	start = 0;
	stop = ft_strlen(s1) - 1;
	lenset = ft_strlen(set);
	while (s1[start] && ft_chr(set, s1[start], lenset) == 0)
		start++;
	while (stop >= start && ft_chr(set, s1[stop], lenset) == 0)
		stop--;
	strtrim = malloc(sizeof(char) * (stop - start + 2));
	if (strtrim == NULL)
		return (NULL);
	ft_strlcpy(strtrim, s1 + start, (stop - start + 2));
	return (strtrim);
}
