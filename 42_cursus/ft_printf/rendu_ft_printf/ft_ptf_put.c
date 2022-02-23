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

int	ft_print_i_or_d(va_list *ap)
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

int	ft_print_p(va_list *ap)
{
	unsigned long int	uli;
	char				*hexbase;

	hexbase = "0123456789abcdef";
	uli = va_arg(*ap, unsigned long int);
	va_end(*ap);
	if (uli)
	{
		ft_putstr_fd("0x", 1);
		return (ft_putuhex(uli, hexbase) + 2);
	}
	else
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
}

int	ft_print_s(va_list *ap)
{
	char	*str;

	str = va_arg(*ap, char *);
	va_end(*ap);
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	ft_print_u(va_list *ap)
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

int	ft_print_xs(va_list *ap, char c)
{
	unsigned int	i;
	char			*hexbase;

	if (c == 'x')
		hexbase = "0123456789abcdef";
	else
		hexbase = "0123456789ABCDEF";
	i = va_arg(*ap, unsigned int);
	va_end(*ap);
	return (ft_puthex(i, hexbase));
}
