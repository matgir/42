/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainft_strlcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:19:53 by mgirardo          #+#    #+#             */
/*   Updated: 2021/12/09 15:04:21 by mgirardo         ###   ########.fr       */
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

int	main(void)
{
	char	strsrc[] = "je suis un test il ce peut que je concatene";
	char	strdest[] = "voila";
	unsigned int	i = 15;

	printf("%s\n%s\n", strsrc, strdest);
	printf("%ld\n", ft_strlcpy(strdest, strsrc, i));
	printf("%s\n%s\n", strsrc, strdest);

	char	strsrc2[] = "je suis un test il ce peut que je concatene";
	char	strdest2[] = "voila";
	unsigned int	i2 = 15;

	printf("%s\n%s\n", strsrc2, strdest2);
	printf("%ld\n", strlcpy(strdest2, strsrc2, i2));
	printf("%s\n%s\n", strsrc2, strdest2);

	return (0);
}
