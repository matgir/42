/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:36:57 by mgirardo          #+#    #+#             */
/*   Updated: 2021/12/14 19:10:37 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

static char	*verif(const char *big, const char *little, size_t i, size_t len)
{
	size_t	l;
	size_t	j;
	size_t	lenlittle;

	lenlittle = ft_strlen(little);
	while (i <= len)
	{
		j = 0;
		if (big[i] == little[j])
		{
			l = i;
			while (l <= (i + lenlittle) && (big[l] || little[j]))
			{
				if (big[l] == little[j])
				{
					if (j == lenlittle)
						return ((char *)&big[l - j]);
					l++;
					j++;
				}
				else
					break ;
			}
		}
		i++;
	}
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	return (verif (big, little, i, len));
}
