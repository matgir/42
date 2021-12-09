/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:36:57 by mgirardo          #+#    #+#             */
/*   Updated: 2021/12/09 12:10:31 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "libft.h"
#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*verif(const char *big, const char *little, size_t i, size_t len)
{
	size_t	l;
	size_t	j;

	while (len-- != 0)
	{
		j = 0;
		if (big[i] == little[j])
		{
			l = i;
			while (l <= (i + ft_strlen(little)) && (big[l] || little[j]))
			{
				if (big[l++] == little[j++])
				{
					if (j == ft_strlen(little))
						return ((char *)&big[l - j]);
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

/*#if defined(LIBC_SCCS) && !defined(lint)
static char sccsid[] = "@(#)strstr.c	8.1 (Berkeley) 6/4/93";
#endif 
//LIBC_SCCS and not lint
#include <sys/cdefs.h>

char	*strnstr(const char *s, const char *find, size_t slen)
{
	char c, sc;
	size_t len;

	if ((c = *find++) != '\0')
	{	
		len = strlen(find);
		do
		{	
			do
			{	
				if (slen-- < 1 || (sc = *s++) == '\0')
					return (NULL);
			}
			while (sc != c);
			if (len > slen)
				return (NULL);
		}
		while (strncmp(s, find, len) != 0);
		s--;
	}
	return ((char *)s);
}*/

int	main(void)
{
	//printf("%s\n", strnstr("bonsoir je suis moi", "e", 8));
	printf("%s\n", ft_strnstr("bonsoir je suis moi", "je", 8));
	return (0);
}
