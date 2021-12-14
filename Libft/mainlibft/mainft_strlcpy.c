/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainft_strlcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:19:53 by mgirardo          #+#    #+#             */
/*   Updated: 2021/12/14 18:17:47 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size);

size_t	strlcpy(char * dst, const char * src, size_t maxlen)
{
	const size_t srclen = strlen(src);

	if (srclen + 1 < maxlen) 
		memcpy(dst, src, srclen + 1);
	else if (maxlen != 0)
	{
		memcpy(dst, src, maxlen - 1);
		dst[maxlen-1] = '\0';
	}
	return (srclen);
}

//interchanger ft_strlcpy et strlcpy pour verif complete

int	main(void)
{
	char	strsrc[] = "lorem";
	char	strdest[] = "rrrrr";
	unsigned int	i = 15;

	printf("\n%s\n%s\n", strsrc, strdest);
	printf("%ld\n", ft_strlcpy(strdest, strsrc, i));
	printf("%s\n%s\n", strsrc, strdest);

	char	strdest2[] = "rrrrr";

	printf("\n%s\n%s\n", strsrc, strdest2);
	printf("%ld\n", strlcpy(strdest2, strsrc, i));
	printf("%s\n%s\n\n", strsrc, strdest2);

	return (0);
}
