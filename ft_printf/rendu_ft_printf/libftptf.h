/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftptf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:00:28 by mgirardo          #+#    #+#             */
/*   Updated: 2022/01/18 17:36:01 by mgirardo         ###   ########.fr       */
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
void 		ft_putpurcent(int *puted, int *i);
void		ft_putstr(char *str);
int			ft_strlen(const char *str);
int			is_variable(char c);
int			print_c(va_list *ap);
int			print_s(va_list *ap);
int			print_variable(char c, va_list *ap);
int			what_variable(const char *str, int *i, va_list *ap);

#endif
