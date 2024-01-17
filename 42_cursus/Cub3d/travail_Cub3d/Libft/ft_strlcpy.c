/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 08:52:45 by itahani           #+#    #+#             */
/*   Updated: 2021/12/06 18:06:00 by itahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int		i;
	unsigned int		len_src;

	i = 0;
	len_src = 0;
	while (src[len_src])
		len_src++;
	if (size > 0)
	{
		while ((i < size - 1) && (i < len_src))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len_src);
}
