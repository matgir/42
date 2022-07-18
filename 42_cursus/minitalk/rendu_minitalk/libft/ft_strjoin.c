/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:28:30 by mgirardo          #+#    #+#             */
/*   Updated: 2022/01/04 16:38:29 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	lens1;
	size_t	lens2;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	join = malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (join == NULL)
		return (NULL);
	ft_strlcpy((ft_memmove(join, s1, lens1) + lens1), s2, (lens2 + 1));
	return (join);
}
