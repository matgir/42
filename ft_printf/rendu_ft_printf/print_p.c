/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:03:06 by mgirardo          #+#    #+#             */
/*   Updated: 2022/01/20 14:40:07 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftptf.h"

int	print_p(va_list *ap)
{
	unsigned long int	uli;
	char				*hexbase;

	hexbase = "0123456789abcdef";
	uli = va_arg(*ap, unsigned long int);
	va_end(*ap);
	if (uli)
	{
		ft_putstr("0x");
		return (ft_putuhex(uli, hexbase) + 2);
	}
	else
	{
		ft_putstr("0x0");
		return (3);
	}
}
