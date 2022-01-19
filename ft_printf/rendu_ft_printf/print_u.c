/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 16:31:18 by mgirardo          #+#    #+#             */
/*   Updated: 2022/01/19 16:41:28 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftptf.h"

int	print_u(va_list *ap)
{
	unsigned int	i;
	int				puted;

	puted = 1;
	i = va_arg(*ap, unsigned int);
	va_end(*ap);
	ft_putunbr(i);
	while (i / 10 != 0)
	{
		puted += 1;
		i = i / 10;
	}
	return (puted);
}
