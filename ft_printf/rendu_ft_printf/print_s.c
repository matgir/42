/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:25:16 by mgirardo          #+#    #+#             */
/*   Updated: 2022/01/20 16:51:40 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_s(va_list *ap)
{
	char	*str;

	str = va_arg(*ap, char *);
	va_end(*ap);
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	ft_putstr(str);
	return (ft_strlen(str));
}
