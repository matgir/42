/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:38:20 by mgirardo          #+#    #+#             */
/*   Updated: 2022/01/04 16:29:53 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (n != 0)
	{
		if (((unsigned char *) s)[i] == (unsigned char) c)
			return ((void *)s + i);
		i++;
		n--;
	}
	return (0);
}
