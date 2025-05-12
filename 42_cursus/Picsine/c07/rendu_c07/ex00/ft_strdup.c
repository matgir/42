/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 09:53:33 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/23 19:32:28 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *src)
{
	unsigned int	i;

	i = 0;
	while (src[i])
		i++;
	return (0);
}

char	*ft_strcpy(char *src, char *dest)
{
	unsigned int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	unsigned int	lsrc;
	char			*dest;

	lsrc = ft_strlen(src);
	dest = malloc (sizeof(char) * (lsrc + 1));
	if (dest == 0)
		return (0);
	return (ft_strcpy(src, dest));
}
