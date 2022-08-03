/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_start_to_put.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:22:06 by mgirardo          #+#    #+#             */
/*   Updated: 2022/01/20 17:00:12 by mgirardo         ###   ########.fr       */
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

int	ft_puthex(unsigned int n, char *hexbase)
{
	unsigned int	ntmp;
	int				i;
	char			*str;
	int				len;

	i = 1;
	ntmp = n;
	while (n / 16 != 0)
	{
		n = n / 16;
		i++;
	}
	len = i;
	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (0);
	str[i] = '\0';
	while (--i >= 0)
	{
		str[i] = hexbase[ntmp % 16];
		ntmp /= 16;
	}
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}

int	ft_putuhex(unsigned long int uli, char *hexbase)
{
	unsigned long int	ntmp;
	int					i;
	char				*str;
	int					len;

	i = 1;
	ntmp = uli;
	while (uli / 16 != 0)
	{
		uli = uli / 16;
		i++;
	}
	len = i;
	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (0);
	str[i] = '\0';
	while (--i >= 0)
	{
		str[i] = hexbase[ntmp % 16];
		ntmp /= 16;
	}
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}

void	ft_putunbr(unsigned int n)
{
	if (n >= 10)
		ft_putunbr(n / 10);
	ft_putchar_fd(n % 10 + 48, 1);
}

void	ft_putpurcent(int *puted, int *i)
{
	ft_putchar_fd('%', 1);
	*puted = *puted + 1;
	*i = *i + 1;
}

int	ft_print_l(va_list *ap)
{
	long int	i;
	int			puted;

	puted = 1;
	i = va_arg(*ap, long int);
	va_end(*ap);
	ft_putlnbr_fd(i, 1);
	if (i < 0)
		puted += 1;
	while (i / 10 != 0)
	{
		puted += 1;
		i = i / 10;
	}
	return (puted);
}
