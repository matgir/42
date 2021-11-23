/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 12:52:12 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/24 18:33:32 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_tablen(char **tab, int size, unsigned int sepsize)
{
	unsigned int	strsize;
	unsigned int	i;
	unsigned int	j;

	strsize = 0;
	i = 0;
	while (i < (unsigned int)size)
	{
		j = 0;
		while (tab[i][j])
		{
			strsize++;
			j++;
		}
		strsize += sepsize;
		i++;
	}
	strsize -= sepsize;
	return (strsize);
}

char	*ft_strcpy(char **strs, char *sep, unsigned int strsize, int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	v;
	unsigned int	w;
	char			*str;

	i = 0;
	j = -1;
	str = malloc(sizeof(*str) * strsize);
	if (str == '\0')
		return (str);
	while (i < strsize)
	{
		while (++j < (unsigned int)size)
		{
			v = -1;
			while (strs[j][++v])
				str[i++] = strs[j][v];
			w = -1;
			while (sep[++w])
				str[i++] = sep[w];
		}
	}
	str[i - w] = '\0';
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	unsigned int	sepsize;
	unsigned int	strsize;
	char			*str;

	if (size == 0)
	{
		str = malloc(sizeof(char));
		str[0] = '\0';
		return (str);
	}
	sepsize = ft_strlen(sep);
	strsize = ft_tablen(strs, size, sepsize);
	str = ft_strcpy(strs, sep, strsize, size);
	return (str);
}
