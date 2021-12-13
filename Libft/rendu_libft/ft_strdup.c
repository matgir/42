/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:41:38 by mgirardo          #+#    #+#             */
/*   Updated: 2021/12/13 17:43:14 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	lens;

	lens = ft_strlen(s);
	dest = malloc (sizeof(char) * (lens + 1));
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, s, lens + 1);
	return (dest);
}
