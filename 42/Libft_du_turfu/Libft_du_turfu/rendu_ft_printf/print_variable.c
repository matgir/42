/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_variable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:04:29 by mgirardo          #+#    #+#             */
/*   Updated: 2022/01/20 15:16:23 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_variable(char c, va_list *ap)
{
	if (c == 'c')
		return (print_c(ap));
	if (c == 's')
		return (print_s(ap));
	if (c == 'i' || c == 'd')
		return (print_i_or_d(ap));
	if (c == 'u')
		return (print_u(ap));
	if (c == 'x' || c == 'X')
		return (print_xs(ap, c));
	if (c == 'p')
		return (print_p(ap));
	return (0);
}