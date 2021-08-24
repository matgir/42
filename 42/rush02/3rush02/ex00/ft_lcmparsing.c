/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 21:39:22 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/22 21:45:34 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

void	ft_lcmparsing(char **tab, char *txt, char *str)
{
	unsigned int	n;
	unsigned int	pow;
	unsigned int	temp;

	n = 0;
	pow = ft_clean_before_nd_nb_paquets(str) - 1;
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
}
