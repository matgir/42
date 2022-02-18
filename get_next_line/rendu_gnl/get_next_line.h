/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 10:15:08 by mgirardo          #+#    #+#             */
/*   Updated: 2022/02/09 16:16:10 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_gnl_strlcpy(char *dst, const char *src, size_t size);
char	*ft_gnl_strjoin(char *line, char *buffer);
int		ft_gnl_strchr(const char *buffer);
char	*get_next_line(int fd);
int		ft_gnl_strlen(const char *str);
void	*ft_memcpy(void	*dest, const void *src, size_t n);

#endif
