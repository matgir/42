/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_variable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:04:29 by mgirardo          #+#    #+#             */
/*   Updated: 2022/01/18 17:54:21 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftptf.h"

int	print_variable(char c, va_list *ap)
{
	if (c == 'c')
		return (print_c(ap));
	if (c == 's')
		return (print_s(ap));
	if (c == )
	return (1); /*		retirer cette ligne une fois printf fini		*/
}