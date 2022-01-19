/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftptf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:00:28 by mgirardo          #+#    #+#             */
/*   Updated: 2022/01/19 16:45:18 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPTF_H
# define LIBFTPTF_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int			ft_printf(const char *str, ...);
void		ft_putchar(char c);
void		ft_putpurcent(int *puted, int *i);
void		ft_putstr(char *str);
int			ft_strlen(const char *str);
int			is_variable(char c);
int			print_c(va_list *ap);
int			print_s(va_list *ap);
int			print_variable(char c, va_list *ap);
int			what_variable(const char *str, int *i, va_list *ap);
int			print_i_or_d(va_list *ap);
void		ft_putnbr(int n);
int			print_u(va_list *ap);
void		ft_putunbr(unsigned int n);

#endif
