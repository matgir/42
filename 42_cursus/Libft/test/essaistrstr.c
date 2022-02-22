/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:36:57 by mgirardo          #+#    #+#             */
/*   Updated: 2021/12/09 11:21:33 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libft.h"

/*size_t  ft_strlen(char *to_find)
{
	size_t  i;

	i = 0;
	while (to_find[i])
		i++;
	return (i);
}*/

char	*verif(const char *haystack, const char *needle, size_t i, size_t j)
{
	size_t	l;

	while (haystack[i])
	{
		if (haystack[i] == needle[j])
		{
			l = i;
			while (l <= (i + ft_strlen(needle)) && (haystack[l] || needle[j]))
			{
				if (haystack[l++] == needle[j++])
				{
					if (j == ft_strlen(needle))
						return ((char *)&haystack[l - j]);
				}
				else
					break ;
			}
		}
		i++;
	}
	return (0);
}

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	return (verif (haystack, needle, i, j));
}

/*char    *strnstr(const char *big, const char *little, size_t len)
  {


  }*/

int	main(void)
{
	printf("%s\n", strstr("bonsoir je suis moi", "e"));
	printf("%s\n", ft_strstr("bonsoir je suis moi", "e"));
	return (0);
}
