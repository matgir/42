/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:03:06 by mgirardo          #+#    #+#             */
/*   Updated: 2022/01/20 16:52:29 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_p(va_list *ap)
{
	unsigned long int	uli;
	char				*hexbase;

	hexbase = "0123456789abcdef";
	uli = va_arg(*ap, unsigned long int);
	va_end(*ap);
	if (uli)
	{
		ft_putstr_fd("0x", 1);
		return (ft_putuhex(uli, hexbase) + 2);
	}
	else
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
}
