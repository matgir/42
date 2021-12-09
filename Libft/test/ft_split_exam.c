/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_exam.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:39:33 by mgirardo          #+#    #+#             */
/*   Updated: 2021/12/09 12:49:59 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int char_is_sep(char c)
{
	if (c == ' ' || c == '	' || c == '\n')
		return (1);
	return (0);
}

unsigned int    get_first_word(char *str)
{
	unsigned int    fw;

	fw = 0;
	while (char_is_sep(str[fw]) == 1)
		fw++;
	return (fw);
}

unsigned int    count_word(char *str, unsigned int fw)
{
	unsigned int    nbword;

	nbword = 0;
	while (str[fw] != '\0')
	{
		while (char_is_sep(str[fw]) == 0 && str[fw] != '\0')
			fw++;
		nbword++;
		while (char_is_sep(str[fw]) == 1 && str[fw] != '\0')
			fw++;
	}
	return (nbword);
}

char    **ft_pick_word(char **tab, int pword, int stop, char *str, int start)
{
	int i;

	i = 0;
	tab[pword] = malloc(sizeof(tab) * (stop - start));
	while (start < stop)
	{
		tab[pword][i] = str[start];
		i++;
		start++;
	}
	tab[pword][i] = '\0';
	return (tab);
}

char    **ft_split(char *str)
{
	unsigned int    nbword;
	unsigned int    pword;
	unsigned int    fw;
	unsigned int    start;
	char            **tab;

	if (str[0] == '\0')
	{
		tab = 0;
		return (tab);
	}
	fw = get_first_word(str);
	if (str[fw] == '\0')
	{
		tab = 0;
		return (tab);
	}
	nbword = count_word(str, fw);
	tab = malloc(sizeof(*tab) * (nbword + 1));
	pword = 0;
	start = fw;
	while (str[fw] && pword < nbword)
	{
		while (char_is_sep(str[fw]) == 0 && str[fw] != '\0')
			fw++;
		tab = ft_pick_word(tab, pword, fw, str, start);
		pword++;
		while (char_is_sep(str[fw]) == 1 && str[fw] != '\0')
			fw++;
		start = fw;
	}
	tab[pword] = 0;
	return (tab);
}

int main()
{
	char **tab;
	unsigned int i;
	unsigned int j;
	unsigned int count;
	char str[] = "	a b c d	e	f\ng h i j k	 l\nm\nn o	p	q r	s 	t\nu v	w 	\nx y	z\n";

	printf("%s\n", str);
	tab = ft_split(str);
	i = 0;
	count = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			write (1, &tab[i][j], 1);
			j++;
			count++;
		}
		write (1, "\n", 1);
		i++;
	}
	printf("%d\n", count);
	return (0);
}
