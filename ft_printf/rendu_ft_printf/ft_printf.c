/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:03:05 by mgirardo          #+#    #+#             */
/*   Updated: 2022/01/18 16:42:32 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftptf.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	ap;
	int		puted;

	i = -1;
	va_start(ap, str);
	puted = 0;
	while (str[++i])
	{
		if (str[i] != '%')
		{
			ft_putchar(str[i]);
			puted++;
		}
		else
		{
			if (str[i + 1] && str[i + 1] == '%')
				ft_putpurcent(&puted, &i);
			else
				puted += what_variable(str, &i, &ap);
		}
	}
	return (puted);
}