/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:57:17 by itahani           #+#    #+#             */
/*   Updated: 2021/12/06 17:43:26 by itahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char			*cpy;
	const size_t	len = ft_strlen(s);

	cpy = (char *)malloc(sizeof(char ) * (len + 1));
	if (!cpy)
		return (NULL);
	while (*s)
		*cpy++ = *s++;
	*cpy = '\0';
	return (cpy - len);
}
