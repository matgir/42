/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_i_or_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:27:47 by mgirardo          #+#    #+#             */
/*   Updated: 2022/01/20 15:15:20 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_i_or_d(va_list *ap)
{
	int	i;
	int	puted;

	puted = 1;
	i = va_arg(*ap, int);
	va_end(*ap);
	ft_putnbr_fd(i, 1);
	if (i < 0)
		puted += 1;
	while (i / 10 != 0)
	{
		puted += 1;
		i = i / 10;
	}
	return (puted);
}
