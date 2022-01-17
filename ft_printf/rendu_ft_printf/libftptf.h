/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftptf.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:00:28 by mgirardo          #+#    #+#             */
/*   Updated: 2022/01/17 18:15:39 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPTF_H
# define LIBFTPTF_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

int			ft_find_%(const char *str);
size_t		ft_strlen(const char *str);
void		ft_putstr(char *str);
int			ft_printf(const char *str, ...);
void		ft_putchar(char c);

#endif
