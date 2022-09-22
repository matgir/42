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

#include "libft.h"

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
	if (c == 'l')
		return (ft_print_l(ap));
	return (0);
}

/*
		This function receive a character that is printable as a variable and is
		gonna start the process of printing it as the output
*/

int	ft_is_variable(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd')
		return (0);
	if (c == 'i' || c == 'u' || c == 'x' || c == 'X')
		return (0);
	if (c == 'l')
		return (0);
	return (1);
}

/*
		This function check if the character after the '%' is printable as a
		variable
*/

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

/*
		this functions receives the character after the '%' and is gonna check
		if it is printable as a variable, then will print it otherwise it will
		simply print the character itself
*/

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

/*
	This is the main functions of printf, it will initiate the va_list 'ap' and
	and send it into the other functions if needed
	va_start allow to read the variable of a multivariadique functions, printf
	is one because the other variabe are representated as '...' after the first
	argument str
	puted is the numbers of character printed on the output
*/