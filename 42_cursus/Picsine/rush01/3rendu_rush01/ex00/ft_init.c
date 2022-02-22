/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 19:16:34 by tliot             #+#    #+#             */
/*   Updated: 2021/08/20 11:07:43 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	*ft_input(char *src)
{
	int	i;
	int	*tab;

	tab = malloc(sizeof(int) * 17);
	i = 0;
	while (*src != '\0')
	{
		if (*src != ' ')
		{
			tab[i] = *src - 48;
			i++;
		}
		src++;
	}
	return (tab);
}

void	ft_zero(int **tab)
{
	int	h;
	int	l;

	h = 0;
	while (h < 6)
	{
		l = 0;
		while (l <= 6)
		{
			tab[h][l] = 0;
			l++;
		}
		h++;
	}
}

int	**ft_init_tab(int *list, int **tab)
{
	int	x;
	int	i;
	int	compteur;

	compteur = -1;
	tab = malloc(sizeof(int *) * 6);
	while (++compteur < 6)
		tab[compteur] = malloc(sizeof(int) * 6);
	ft_zero(tab);
	x = 0;
	i = -1;
	while (x < 4)
		tab[0][++x] = list[++i];
	x = 0;
	while (x < 4)
		tab[5][++x] = list[++i];
	x = 0;
	while (x < 4)
		tab[++x][0] = list[++i];
	x = 0;
	while (x < 4)
		tab[++x][5] = list[++i];
	return (tab);
}
