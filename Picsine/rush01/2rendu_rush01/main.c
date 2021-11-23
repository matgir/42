/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 12:12:09 by tliot             #+#    #+#             */
/*   Updated: 2021/08/15 17:26:39 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
void	ft_putchar(char c);
/////////////////////////////////////
// 		  remplissage ligne       //
///////////////////////////////////

void	ft_41_rpligne(int **tab)
{
	int	h;
	int	l;

	h = 1;
	while (h < 5)
	{	
		if (tab[h][0] == 4)
		{
			l = 1;
			while (l < 5)
			{
				tab[h][l] = l;
				l++;
			}	
		}
		h++;
	}
}

////////////////////////////////////
//  remplissage inverse ligne    //
//////////////////////////////////
void	ft_41_rpligne_inv(int **tab)
{
	int	i;
	int	h;
	int	l;

	h = 1;
	while (h < 5)
	{	
		if (tab[h][5] == 4)
		{	
			i = 1;
			l = 4;
			while (l > 0)
			{
				tab[h][l] = i;
				l--;
				i++;
			}	
		}
		h++;
	}
}

////////////////////////////////////
//       remplissage colone      //
//////////////////////////////////
void	ft_41_rpcolone(int **tab)
{
	int	l;
	int	h;

	l = 1;
	while (l < 5)
	{	
		if (tab[0][l] == 4)
		{
			h = 1;
			while (h < 5)
			{
				tab[h][l] = h;
				h++;
			}	
		}
		l++;
	}
}

////////////////////////////////////
//  remplissage inverse colone   //
//////////////////////////////////
void	ft_41_rpcolone_inv(int **tab)
{	
	int	l;
	int	h;
	int	i;

	l = 1;
	while (l < 5)
	{	
		if (tab[5][l] == 4)
		{
			i = 1;
			h = 4;
			while (h > 0)
			{
				tab[h][l] = i;
				h--;
				i++;
			}	
		}
		l++;
	}
}

////////////////////////////////////
//            Affichage          //
//////////////////////////////////
void	ft_affichage(int **tab)
{
	int	y;
	int	z;

	y = 0;
	while (y < 6)
	{
		z = 0;
		while (z < 6)
		{
			ft_putchar(tab[z][y] + '0');
			z++;
		}
		y++;
		write(1, "\n", 1);
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	**ft_init_tab(int **tab)
{
	int	x;
	int	h;
	int	l;

	x = 0;
	tab = malloc(sizeof(int *) * 6);
	while (x < 6)
	{
		tab[x] = malloc(sizeof(int *) * 6);
		x++;
	}
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
	return (tab);
}

int	main(void )
{
// int tab_contour[16] = {1,2,3,4,4,3,2,1,1,2,3,4,4,3,2,1};
	int	**tab;

	tab = NULL;
	tab = ft_init_tab(tab);
	tab[0][1] = 1;
	tab[0][2] = 2;
	tab[0][3] = 3;
	tab[0][4] = 4;
	tab[5][1] = 4;
	tab[5][2] = 3;
	tab[5][3] = 2;
	tab[5][4] = 1;
	tab[1][0] = 1;
	tab[2][0] = 2;
	tab[3][0] = 3;
	tab[4][0] = 4;
	tab[1][5] = 4;
	tab[2][5] = 3;
	tab[3][5] = 2;
	tab[4][5] = 1;
	ft_41_rpligne(tab);
	ft_41_rpligne_inv(tab);
	ft_41_rpcolone(tab);
	ft_41_rpcolone_inv(tab);
	ft_affichage(tab);
}
