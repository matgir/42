/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:44:37 by itahani           #+#    #+#             */
/*   Updated: 2022/01/07 15:30:11 by itahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	iend(char const *s1, char const *set)
{
	unsigned long int	i;
	unsigned long int	j;

	i = ft_strlen((char *)s1) - 1;
	j = 0;
	while (set[j] != '\0' && i != 0)
	{
		if (s1[i] == set[j])
		{
			i--;
			j = 0;
		}
		else
			j++;
	}
	return (i + 1);
}

size_t	ibeg(char const *s1, char const *set)
{
	unsigned long int	i;
	unsigned long int	j;

	i = 0;
	j = 0;
	while (set[j] != '\0' && s1[i] != '\0')
	{
		if (s1[i] == set[j])
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char					*res;
	unsigned long int		i;
	unsigned long int		j;

	if (!s1 || !set)
		return (NULL);
	j = 0;
	i = ibeg(s1, set);
	if (i == ft_strlen(s1))
		return ("");
	res = malloc(sizeof (char) * ((iend(s1, set) - i + 1)));
	if (res == NULL)
		return (NULL);
	while ((i + j) < iend(s1, set))
	{
		res[j] = s1[i + j];
		j++;
	}
	res[j++] = '\0';
	return (res);
}
/*
#include <stdio.h>
int	main()
{
	printf("[%s]\n", ft_strtrim("abcab", "abc"));
	return (0);
}*/
