/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 10:55:16 by itahani           #+#    #+#             */
/*   Updated: 2021/12/01 11:59:48 by itahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strlen(char *str);

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	long unsigned int	len_dst;
	long unsigned int	i;
	int					len_src;
	int					j;

	len_dst = ft_strlen((char *)dst);
	len_src = ft_strlen((char *)src);
	i = 0;
	j = 0;
	if (len_dst > size)
		return (size + len_src);
	while (dst[i] != '\0')
		i++;
	while ((i < size - 1) && (src[j] != '\0'))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (len_src + len_dst);
}
