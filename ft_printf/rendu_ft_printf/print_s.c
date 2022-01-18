/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:25:16 by mgirardo          #+#    #+#             */
/*   Updated: 2022/01/18 17:37:31 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftptf.h"

int	print_s(va_list *ap)
{
	char *str;

	str = va_arg(*ap, char *);
	ft_putstr(str);
	va_end(*ap);
	return (ft_strlen(str));
}
