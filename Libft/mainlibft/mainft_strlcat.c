/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainft_strlcat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:30:58 by mgirardo          #+#    #+#             */
/*   Updated: 2021/12/09 17:12:21 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stddef.h>
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size);

size_t	strlcat(dst, src, siz)
	char *dst;
	const char *src;
	size_t siz;
{
	register char *d = dst;
	register const char *s = src;
	register size_t n = siz;
	size_t dlen;

	/* Find the end of dst and adjust bytes left but don't go past end */
	while (n-- != 0 && *d != '\0')
		d++;
	dlen = d - dst;
	n = siz - dlen;

	if (n == 0)
		return (dlen + strlen(s));
	while (*s != '\0') 
	{
		if (n != 1) 
		{
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';

	return (dlen + (s - src));	/* count does not include NUL */
}

int	main(void)
{
	char		dest[50] = "bonsoir";
	const char	src[] = "je suis la suite";
	size_t		i = 8;

	printf("%s\n%s", dest, src);
	printf("\n%ld\n", strlcat(dest, src, i));
	printf("%s\n%s\n", dest, src);

	char		dest1[50] = "bonsoir";
	const char	src1[] = "je suis la suite";
	size_t		i1 = 8;

	printf("\n%s\n%s", dest1, src1);
	printf("\n%ld\n", ft_strlcat(dest1, src1, i1));
	printf("%s\n%s\n", dest1, src1);
}
