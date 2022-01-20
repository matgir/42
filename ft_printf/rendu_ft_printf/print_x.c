/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x_or_X.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 10:25:27 by mgirardo          #+#    #+#             */
/*   Updated: 2022/01/20 11:51:47 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftptf.h"

int	print_x(va_list *ap)
{
	unsigned int	i;

	i = va_arg(*ap, unsigned int);
	va_end(*ap);
	return (ft_puthex(i));
}
