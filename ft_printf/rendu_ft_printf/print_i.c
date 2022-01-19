/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:27:47 by mgirardo          #+#    #+#             */
/*   Updated: 2022/01/19 16:11:05 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftptf.h"

int print_i(va_list *ap)
{
	int i;
	int puted;

	puted = 1;
	i = va_arg(*ap, int);
	va_end(*ap);
	ft_putnbr(i);
	if (i < 0)
		puted += 1;
	while (i / 10 != 0)
		puted += 1;
	return (puted);
}
