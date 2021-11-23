/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_all.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 12:52:07 by llepiney          #+#    #+#             */
/*   Updated: 2021/08/22 19:28:42 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
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
	{
		if (tab[n][2] == '0')
			ft_parsing(txt, ten_ten(tab[n][1], tab[n][2]));
		else
		{
			temp = solo_char(tab[n][2]);
			ft_parsing(txt,ten_ten(tab[n][1], '0'));
			ft_putchar(' ');
			ft_parsing(txt, temp);
		}
	}
	if (pow != 0)
	{
		ft_putchar(' ');
		ft_parsing(txt, ten_power(pow));
	}
}

void	aff_pack2(char *txt, char **tab, int n, int pow)
{
	char	*temp;

	temp = solo_char(tab[n][0]);
	ft_parsing(txt, temp);
	ft_putchar(' ');
	ft_parsing(txt, "100");
	if ((tab[n][1] != '0' && tab[n][2] != '0') || (tab[n][1] != '0' && tab[n][2] == '0'))
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
	{
		ft_parsing(txt, ten_ten(tab[n][1], tab[n][2]));
	}
	else
	{
		if (tab[n][2] == '0')
			ft_parsing(txt, ten_ten(tab[n][1], tab[n][2]));
		else
		{
			temp = solo_char(tab[n][2]);
			ft_parsing(txt,ten_ten(tab[n][1], '0'));
			ft_putchar(' ');
			ft_parsing(txt, temp);
		}
	}
	if (pow != 0)
	{
		ft_putchar(' ');
		ft_parsing(txt, ten_power(pow));
	}
}
/*
int	main(void)
{
	char	*test[] = {"124", "123", "123"};
	char	chepa[] = "numbers.dict.txt";
	int	n;
	int	pow;

	n = 0;
	pow = 2;
	while (pow >= 0)
	{
		if (test[n][0] == '0')
			aff_pack1(chepa, test, n, pow);
		else
			aff_pack2(chepa, test, n, pow);
		if (pow != 0)
			ft_putchar(' ');
		n++;
		pow--;
	}
	ft_putchar('\n');
	return (0);
}
*/

/*
int	main(int argc, char **argv)
{
	char	chepa[] = "numbers.dict.txt";
	int	n;
	int	pow;

	n = 1;
	pow = argc - 2;
	while (pow >= 0)
	{
		if (argv[n][0] == '0')
			aff_pack1(chepa, argv, n, pow);
		else
			aff_pack2(chepa, argv, n, pow);
				if (pow != 0)
					ft_putchar(' ');
		n++;
		pow--;
	}
	ft_putchar('\n');
	return (0);
}
*/
