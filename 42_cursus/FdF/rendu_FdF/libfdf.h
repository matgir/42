/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:45:24 by mgirardo          #+#    #+#             */
/*   Updated: 2022/03/31 16:45:27 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_FDF_H
# define LIB_FDF_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>

# define BUFFER_SIZE 42

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
void		ft_gnl_strlcpy(char *dst, const char *src, size_t size);
char		*ft_gnl_strjoin(char *line, char *buffer);
char		*get_next_line(int fd);
int			ft_gnl_strlen(const char *str);
char	    **ft_fdf_split(char const *s, char c, int *x);
char	    **free_all(char **tab);
int 	nw(char const *s, char c, size_t stop);
int	    dbt(char const *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
/*(don't forget to compile with :	ft_printf.c
 ft_ptf_put.c
 ft_ptf_start_to_put.c
 ft_putchar_fd.c
 ft_putnbr_fd.c
 ft_putstr_fd.c
 ft_strlen.c)*/

#endif
