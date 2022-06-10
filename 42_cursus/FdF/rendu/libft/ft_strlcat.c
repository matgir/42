/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:30:11 by mgirardo          #+#    #+#             */
/*   Updated: 2022/01/04 16:39:14 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*		lors de lexecution si ldst < lsrc et size > ldst+1
 *		alors src va etre modifier et cela est normal		*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	ldst;
	size_t	lsrc;
	size_t	i;

	ldst = ft_strlen(dst);
	lsrc = ft_strlen(src);
	i = 0;
	if (ldst >= size)
		return (lsrc + size);
	while ((size - ldst - 1) != 0 && src[i])
	{
		dst[ldst + i] = src[i];
		size--;
		i++;
	}
	dst[ldst + i] = '\0';
	return (lsrc + ldst);
}
