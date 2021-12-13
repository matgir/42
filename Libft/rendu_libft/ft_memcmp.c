/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:34:55 by mgirardo          #+#    #+#             */
/*   Updated: 2021/12/13 14:48:59 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (n != 0)
	{
		if (((unsigned char *) s1)[i] != ((unsigned char *) s2)[i])
			break;
		i++;
		n--;
	}
	return (((unsigned char *) s1)[i] - ((unsigned char *) s2)[i]);
}
