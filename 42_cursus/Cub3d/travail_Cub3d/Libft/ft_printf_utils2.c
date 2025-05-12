/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:12:10 by itahani           #+#    #+#             */
/*   Updated: 2022/04/14 16:22:46 by itahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

void	ft_putnbr_base(unsigned int nbr, char type, int *ret_value)
{
	char	*hexa_base_maj;
	char	*hexa_base_min;

	hexa_base_min = "0123456789abcdef";
	hexa_base_maj = "0123456789ABCDEF";
	if (nbr > 15)
		ft_putnbr_base(nbr / 16, type, ret_value);
	if (type == 'X')
		ft_putchar(hexa_base_maj[nbr % 16], ret_value);
	else if (type == 'x')
		ft_putchar(hexa_base_min[nbr % 16], ret_value);
}

void	ft_putnbr_base_p(unsigned long long int nbr, int *ret_value)
{
	char	*hexa_base_min;

	hexa_base_min = "0123456789abcdef";
	if (nbr > 15)
		ft_putnbr_base_p(nbr / 16, ret_value);
	ft_putchar(hexa_base_min[nbr % 16], ret_value);
}

void	ft_put_p(unsigned long long int nbr, int *ret_value)
{
	if (nbr == 0)
	{
		ft_putstr("(nil)", ret_value);
		return ;
	}
	ft_putstr("0x", ret_value);
	ft_putnbr_base_p(nbr, ret_value);
}
