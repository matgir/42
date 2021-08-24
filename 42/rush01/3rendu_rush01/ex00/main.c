/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 19:06:43 by tliot             #+#    #+#             */
/*   Updated: 2021/08/15 21:48:32 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>

int		*ft_input(char *src);
void	ft_zero(int **tab);
int		**ft_init_tab(int *list, int **tab);
void	ft_putchar(char c);
void	ft_41_rpligne(int **tab);
void	ft_41_rpcolone(int **tab);
int		ck_arg(int ac, char **av);
void	ft_12_rpligne(int **tab);
void	ft_12_rpcolone(int **tab);
void	ft_1_23l(int **tab);
void	ft_1_23c(int **tab);

////////////////////////////////////
//            Affichage          //
//////////////////////////////////
void	ft_affichage(int **tab)
{
	int	y;
	int	z;

	y = 1;
	while (y < 5)
	{
		z = 1;
		while (z < 5)
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

int	main(int ac, char **av)
{
	int	**tab;
	int	*list;

	if (ck_arg(ac, av) == 1)
		return (1);
	list = ft_input(av[1]);
	tab = NULL;
	tab = ft_init_tab(list, tab);
	ft_41_rpligne(tab);
	ft_41_rpcolone(tab);
	ft_12_rpligne(tab);
	ft_12_rpcolone(tab);
	ft_1_23l(tab);
	ft_1_23c(tab);
	ft_affichage(tab);
	return (0);
}
