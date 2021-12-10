/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:59:11 by mgirardo          #+#    #+#             */
/*   Updated: 2021/12/10 17:28:58 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i])
	{
		if (s[i] == (const char)c)
		{
			j = i;
			while (s[j])
			{
				if (s[j] == (const char)c)
					break;
				j++;
			}
		}
		i++;
	}
	return (0);
}
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	nb_c_in_s;
	size_t	i;

	nb_c_in_s = 0;
	i = ft_strlen(s);
	while (s)
	{
		if (*s == (const char)c)
			nb_c_in_s++;
		s++;
	}
	s -= i;
	i = 0;
	while (s)
	{
		if (*s == (const char)c)
			i++;
		if (*s == (const char)c && i == nb_c_in_s)
			return ((char *)s);
		s++;
	}
	return (0);
}
