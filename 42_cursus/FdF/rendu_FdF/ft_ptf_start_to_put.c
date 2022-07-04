/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_put.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 14:27:47 by mgirardo          #+#    #+#             */
/*   Updated: 2022/01/20 15:15:20 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

/*
		In order to use it everywhere :
		include your own .h as follow

		#ifndef NOM_LIB_H
		# define NOM_LIB_H

		# include <stddef.h>
		# include <stdlib.h>
		# include <unistd.h>
		# include <stdarg.h>

		int			ft_printf(const char *str, ...);
		void		ft_putchar_fd(char c, int fd);
		int			ft_puthex(unsigned int n, char *hexbase);
		void		ft_putnbr_fd(int n, int fd);
		void		ft_putpurcent(int *puted, int *i);
		void		ft_putstr_fd(char *s, int fd);
		int			ft_putuhex(unsigned long int uli, char *hexbase);
		void		ft_putunbr(unsigned int n);
		size_t		ft_strlen(const char *str);
		int			ft_is_variable(char c);
		int			ft_print_i_or_d(va_list *ap);
		int			ft_print_p(va_list *ap);
		int			ft_print_s(va_list *ap);
		int			ft_print_u(va_list *ap);
		int			ft_print_variable(char c, va_list *ap);
		int			ft_print_xs(va_list *ap, char c);
		int			ft_what_variable(const char *str, int *i, va_list *ap);
			(don't forget to compile with :	ft_printf.c
											ft_ptf_put.c
											ft_ptf_start_to_put.c
											ft_putchar_fd.c
											ft_putnbr_fd.c
											ft_putstr_fd.c
											ft_strlen.c)

		#endif
*/

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

/*
	this functions will print the i or d received on the output and will also
	increment puted in order to know how much character was printed as the
	output
*/

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

/*
	this functions will print the U received on the output and will also
	increment puted in order to know how much character was printed as the
	output
*/

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
