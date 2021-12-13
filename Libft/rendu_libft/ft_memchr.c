/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:38:20 by mgirardo          #+#    #+#             */
/*   Updated: 2021/12/13 17:08:41 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int o, size_t n)
{
	size_t	i;

	i = 0;
	while (n != 0)
	{
		if (((unsigned char *) s)[i] == (unsigned char) o)
			return ((void *)s + i);
		i++;
		n--;
	}
	return (0);
}
