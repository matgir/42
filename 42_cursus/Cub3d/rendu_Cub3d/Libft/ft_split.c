/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <itahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:27:43 by itahani           #+#    #+#             */
/*   Updated: 2023/10/14 00:35:27 by itahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	nb_lignes(const char *s, char c)
{
	int	rows;

	rows = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
			rows++;
		while (*s && *s != c)
			s++;
	}
	return (rows);
}

static void	*ft_free(char **str_arr)
{
	int	i;

	i = -1;
	while (str_arr[++i])
		free(str_arr[i]);
	free(str_arr);
	return (NULL);
}

static int	ft_wordlen(const char *s, char c)
{
	char	*str_end;

	str_end = ft_strchr(s, c);
	if (!str_end)
		return (ft_strlen(s));
	else
		return (str_end - s);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		n;
	char	**str_arr;

	if (!s)
		return (NULL);
	str_arr = malloc(sizeof(char *) * (nb_lignes(s, c) + 1));
	if (!str_arr)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
		{
			n = ft_wordlen(s, c);
			str_arr[i++] = ft_substr(s, 0, n);
			if (!str_arr[i - 1])
				return (ft_free(str_arr));
			s += n;
		}
	}
	str_arr[i] = NULL;
	return (str_arr);
}

char	**ft_split_solong_bonus(const char *s, char c)
{
	int		i;
	int		n;
	char	**str_arr;

	if (!s)
		return (NULL);
	str_arr = malloc(sizeof(char *) * (nb_lignes(s, c) + 2));
	if (!str_arr)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && *s != c)
		{
			n = ft_wordlen(s, c);
			str_arr[i++] = ft_substr(s, 0, n);
			if (!str_arr[i - 1])
				return (ft_free(str_arr));
			s += n;
		}
	}
	ligne_sup(str_arr, &i);
	return (str_arr);
}

/*
char	**res_malloc(char const *s, char c)
{
	int		i;
	int		n;
	char	**mal;

	i = 0;
	n = 0;
	while (s[i])
	{
		while (s[i] != c && s[i] != '\0')
		{
			i++;
		}

		n++;
		i++;
	}
	mal = malloc(sizeof(char *) * (n + 1));
	if (mal == NULL)
		return (NULL);
	mal[n] = 0;
	return (mal);
}

char	*new_mallocked_chain(char const **s, char c)
{
	char		*mal;
	int	i;
	int			len;

	len = 0;
	i = 0;
	while ((s[0][i] != c) && (s[0][i] != '\0'))
		i++;
	mal = malloc(sizeof (char) * (i + 1));
	if (mal == NULL)
		return (NULL);
	i = 0;
	len = 0;
	while ((s[0][i] != c) && (s[0][i] != '\0'))
	{
		mal[len] = s[0][i];
		len++;
		i++;
	}
	mal[len] = '\0';
	while ((s[0][i] == c) && (s[0][i] != '\0'))
		i++;
	s[0] += i;
	return (mal);
}

char	**ft_split(char const *s, char c)
{
	int		n;
	int		m;
	char	**res;

	if (!s || !c)
		return (0);
	m = 0;
	res = res_malloc(s, c);
	if (res == NULL)
		return (NULL);
	n = 0;
	while (*s == c)
		s++;
	while (*s)
	{
		res[n] = new_mallocked_chain(&s, c);
		if (res[n] == NULL)
		{
			while (m <= n)
			{
				free(res[m]);
				m++;
			}
			free(res);
		}
		n++;
	}
	res[n] = NULL;
	return (res);
}*/
/*
int main (int argc, char **argv)
{
	(void)argc;
	int	i = -1;
	char	**tab = ft_split(argv[1], argv[2][0]);
	while (tab[++i] != NULL)
		printf("[%s]\n", tab[i]);
	i++;
	//printf("[%s]\n", tab[i]);
	return (0);
}*/
