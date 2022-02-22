/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_all.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 12:52:07 by llepiney          #+#    #+#             */
/*   Updated: 2021/08/22 20:55:40 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include "library.h"

void	aff_pack1(char *txt, char **tab, int n, int pow)
{
	char	*temp;

	if (tab[n][0] == '0' && tab[n][1] == '0' && tab[n][2] == '0')
	{
		if (pow != 0)
			ft_parsing(txt, ten_power(pow));
		return ;
	}
	if (tab[n][1] == '0')
	{
		temp = solo_char(tab[n][2]);
		ft_parsing(txt, temp);
	}
	else if (tab[n][1] == '1')
		ft_parsing(txt, ten_ten(tab[n][1], tab[n][2]));
	else
		ft_annexe1(txt, tab, n);
	if (pow != 0)
	{
		ft_putchar(' ');
		ft_parsing(txt, ten_power(pow));
	}
}

void	aff_pack2(char *txt, char **tab, int n, int pow)
{
	char	*temp;

	ft_annexe2(txt, tab, n);
	if ((tab[n][1] != '0' && tab[n][2] != '0')
		|| (tab[n][1] != '0' && tab[n][2] == '0'))
		ft_putchar(' ');
	if (tab[n][1] == '0')
	{
		if (tab[n][2] != '0')
		{
			ft_putchar(' ');
			temp = solo_char(tab[n][2]);
			ft_parsing(txt, temp);
		}
	}
	else if (tab[n][1] == '1')
		ft_parsing(txt, ten_ten(tab[n][1], tab[n][2]));
	else
		ft_annexe1(txt, tab, n);
	if (pow != 0)
	{
		ft_putchar(' ');
		ft_parsing(txt, ten_power(pow));
	}
}

void	ft_annexe1(char *txt, char **tab, int n)
{
	char	*temp;

	if (tab[n][2] == '0')
		ft_parsing(txt, ten_ten(tab[n][1], tab[n][2]));
	else
	{
		temp = solo_char(tab[n][2]);
		ft_parsing(txt, ten_ten(tab[n][1], '0'));
		ft_putchar(' ');
		ft_parsing(txt, temp);
	}
}

void	ft_annexe2(char *txt, char **tab, int n)
{
	char	*temp;

	temp = solo_char(tab[n][0]);
	ft_parsing(txt, temp);
	ft_putchar(' ');
	ft_parsing(txt, "100");
}
