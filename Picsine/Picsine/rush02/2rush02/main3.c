/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 16:38:28 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/22 20:50:55 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "library.h"

int	ft_lenstr(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	unsigned int	pow;
	char			*str;
	char			*strcpy;
	char			**tab;
	unsigned int	n;
	char			*txt;
	unsigned int	temp;

	n = 0;
	str = 0;
	if (argc < 2 || argc > 3)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (argc == 3)
	{
		txt = argv[1];
		str = argv[2];
	}
	else if (argc == 2)
	{
		txt = "numbers.dict.txt";
		str = argv[1];
	}
	if (ft_chek_arg(str) != 0 || ft_clean_before_nd_nb_paquets(str) > 13)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	pow = ft_clean_before_nd_nb_paquets(str) - 1;
	strcpy = 0;
	if (ft_lenstr(str) % 3 == 0)
	{
		(void) strcpy;
		tab = split(str);
	}
	else
	{
		strcpy = ft_strcpy(str);
		tab = split(strcpy);
	}
	temp = pow + 1;
	while (n < temp && pow >= 0)
	{
		while (n != 0 && n < temp && triple_zero(tab, n) == 1 && pow > 0)
		{
			n++;
			pow--;
		}
		if (tab[n][0] == '0')
			aff_pack1(txt, tab, n, pow);
		else
		{
			aff_pack2(txt, tab, n, pow);
		}
		if (pow != 0)
			ft_putchar(' ');
		n++;
		pow--;
	}
	ft_putchar('\n');
	return (0);
}
