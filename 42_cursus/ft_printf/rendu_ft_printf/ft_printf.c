/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:03:05 by mgirardo          #+#    #+#             */
/*   Updated: 2022/01/20 16:25:04 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_print_variable(char c, va_list *ap)
{
	if (c == 'c')
	{
		ft_putchar_fd(va_arg(*ap, int), 1);
		va_end(*ap);
		return (1);
	}
	if (c == 's')
		return (ft_print_s(ap));
	if (c == 'i' || c == 'd')
		return (ft_print_i_or_d(ap));
	if (c == 'u')
		return (ft_print_u(ap));
	if (c == 'x' || c == 'X')
		return (ft_print_xs(ap, c));
	if (c == 'p')
		return (ft_print_p(ap));
	return (0);
}

int	ft_is_variable(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd')
		return (0);
	if (c == 'i' || c == 'u' || c == 'x' || c == 'X')
		return (0);
	return (1);
}

int	ft_what_variable(const char *str, int *i, va_list *ap)
{
	int	puted;

	if (str[*i + 1] && ft_is_variable(str[*i + 1]) == 0)
	{
		puted = ft_print_variable(str[*i + 1], ap);
		*i = *i + 1;
		return (puted);
	}
	else
	{
		ft_putchar_fd(str[*i + 1], 1);
		*i = *i + 1;
		return (1);
	}
}

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
			ft_putchar_fd(str[i], 1);
			puted++;
		}
		else
		{
			if (str[i + 1] && str[i + 1] == '%')
				ft_putpurcent(&puted, &i);
			else
				puted += ft_what_variable(str, &i, &ap);
		}
	}
	return (puted);
}
