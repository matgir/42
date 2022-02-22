/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:59:11 by mgirardo          #+#    #+#             */
/*   Updated: 2021/12/15 11:09:22 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if (s[0] == '\0' && c == '\0')
		return ((char *)s);
	else
	{
		while (i >= 0)
		{
			if (s[i] == (const char)c)
				return ((char *)s + i);
			i--;
		}
	}
	return (0);
}
