/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainft_strnstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 12:23:46 by mgirardo          #+#    #+#             */
/*   Updated: 2021/12/15 12:17:18 by mgirardo         ###   ########.fr       */
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

	printf("%ld\n", slen);
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
	char s2[] = "dolor";
	char haystack[30] = "aaabcabcd";
	char needle[10] = "aabc";
	//char *empty = (char *)"";

	printf("%s\n", strnstr(s1, s2, 20));
	printf("%s\n", ft_strnstr(s1, s2, 20));
	printf("%s\n", strnstr(haystack, "cd", 10));
	printf("%s\n", ft_strnstr(haystack, "cd", 10));
	printf("%s\n", strnstr(haystack, needle, -1));
	printf("%s\n", ft_strnstr(haystack, needle, -1));
	printf("%s\n", strnstr(haystack, "aaabc", 5));
	printf("%s\n", ft_strnstr(haystack, "aaabc", 5));
	printf("%s\n", strnstr(haystack, "abcd", 9));
	printf("%s\n", ft_strnstr(haystack, "abcd", 9));
	printf("%s\n", strnstr(haystack, "a", 1));
	printf("%s\n", ft_strnstr(haystack, "a", 1));
	return (0);
}
