/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <itahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:07:45 by itahani           #+#    #+#             */
/*   Updated: 2023/10/13 23:58:52 by itahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	len_start;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	s += start;
	len_start = ft_strlen(s);
	if (len > len_start)
		len = len_start;
	sub = (char *) malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (i++ < len)
		*sub++ = *s++;
	*sub = '\0';
	return (sub - len);
}

/*char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;
	size_t			i;

	i = 0;
	res = malloc(sizeof (char) * (len));
	if ((res == NULL) || (start > ft_strlen(s)))
		return (NULL);
	while (s[start] && (i < len))
	{
		res[i] = s[start];
		start++;
		i++;
	}
	res[i] = '\0';
	return (res);
}*/
/*
#include <stdio.h>
int main()
{
	printf("%s", ft_substr("hello", 3, 3));
	return (0);
}*/
