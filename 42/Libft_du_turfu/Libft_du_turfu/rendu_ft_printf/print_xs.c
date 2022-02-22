/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 10:25:27 by mgirardo          #+#    #+#             */
/*   Updated: 2022/01/20 15:16:35 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_xs(va_list *ap, char c)
{
	unsigned int	i;
	char			*hexbase;

	if (c == 'x')
		hexbase = "0123456789abcdef";
	else
		hexbase = "0123456789ABCDEF";
	i = va_arg(*ap, unsigned int);
	va_end(*ap);
	return (ft_puthex(i, hexbase));
}
