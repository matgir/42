/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:30:11 by mgirardo          #+#    #+#             */
/*   Updated: 2021/12/09 17:10:16 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	
}*/

int    ft_strlen(char *str)
{	
    int    i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

unsigned int    ft_strlcat(char *dest, char *src, unsigned int size)
{
    unsigned int    i;
    unsigned int    len_src;
    unsigned int    len_dest;

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
    return ( (len_src + len_dest));
}
