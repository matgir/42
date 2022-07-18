/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:36:57 by mgirardo          #+#    #+#             */
/*   Updated: 2022/01/04 16:41:32 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	l;
	size_t	j;

	i = 0;
	if (little[0] == 0)
		return ((char *)big);
	while (i < len && big[i])
	{
		j = 0;
		if (big[i] == little[j])
		{
			l = i;
			while (big[l] && little[j] && l < len)
			{
				if (big[l] == little[j] && little[j + 1] == '\0')
					return ((char *)&big[l - j]);
				l++;
				j++;
			}
		}
		i++;
	}
	return (0);
}
