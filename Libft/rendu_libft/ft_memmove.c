/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:28:30 by mgirardo          #+#    #+#             */
/*   Updated: 2021/12/08 14:56:51 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/*void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp;
	size_t		n_tmp;
	size_t		i;

	n_tmp = 0;
	tmp = malloc(sizeof(*tmp) * n);
	i = 0;
	while (n_tmp++ != n)
		tmp[i++] = *((unsigned const char *) src++);
	i = 0;
	while (n-- != 0)
		*((unsigned char *) dest++) = tmp[i++];
	return (dest);
}*/

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	tmp;

	while (n-- != 0)
	{
		tmp = *((unsigned const char *) src++);
		*((unsigned char *) dest++) = tmp;
	}
	return (dest);
}
