/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainft_strnstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:23:46 by mgirardo          #+#    #+#             */
/*   Updated: 2021/12/09 12:28:34 by mgirardo         ###   ########.fr       */
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
	printf("%s\n", strnstr("bonsoir je suis moi", " ", 12));
	printf("%s\n", ft_strnstr("bonsoir je suis moi", " ", 12));
	return (0);
}
