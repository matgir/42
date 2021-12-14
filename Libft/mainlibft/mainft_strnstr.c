/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainft_strnstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:23:46 by mgirardo          #+#    #+#             */
/*   Updated: 2021/12/14 19:07:21 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len);

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
}

int	main(void)
{
	char s1[] = "lorem ipsum dolor sit amet";
	char s2[] = "lorem";
	size_t len = 15;

	printf("%s\n", strnstr(s1, s2, len));
	printf("%s\n", ft_strnstr(s1, s2, len));
	return (0);
}
