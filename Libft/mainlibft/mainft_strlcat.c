/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainft_strlcat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:30:58 by mgirardo          #+#    #+#             */
/*   Updated: 2021/12/10 15:15:25 by mgirardo         ###   ########.fr       */
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

int	ft_strlen(const char *str)
{
	int	w;

	w = 0;
	while (str[w])
		w++;
	return (w);
}

size_t	gstrlcat(char *dest, const char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len_src;
	unsigned int	len_dest;

	len_src = ft_strlen(src);
	len_dest = ft_strlen(dest);
	i = 0;
	if (len_dest >= size)
		return (len_src + size);
	while (src[i] && ((len_dest + i) < (size - 1)))
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (len_src + len_dest);
}

int	main(void)
{
	char		dest[16] = "bonsoir";
	const char	src[] = " je suis la suite";
	size_t		i = 8;

	printf("%s\n%s", dest, src);
	printf("\n%ld\n", strlcat(dest, src, i));
	printf("%s\n%s\n", dest, src);

	char		dest1[16] = "bonsoir";

	printf("\n%s\n%s", dest1, src);
	printf("\n%ld\n", ft_strlcat(dest1, src, i));
	printf("%s\n%s\n", dest1, src);

	char		dest2[16] = "bonsoir";

	printf("\n%s\n%s", dest2, src);
	printf("\n%ld\n", gstrlcat(dest2, src, i));
	printf("%s\n%s\n", dest2, src);

}
