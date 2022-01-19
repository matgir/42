/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_variable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:04:29 by mgirardo          #+#    #+#             */
/*   Updated: 2022/01/19 16:47:29 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftptf.h"

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
	return (1);
}

/*		retirer cette return (1) une fois printf fini		*/
