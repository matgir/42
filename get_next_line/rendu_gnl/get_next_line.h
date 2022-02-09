/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 10:15:08 by mgirardo          #+#    #+#             */
/*   Updated: 2022/02/09 10:28:54 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlcpy(char *line, char *buffer, size_t size);
char	*ft_strjoin(char *line, char *buffer);
int		ft_strchr(char *buffer, char c);
char	*ft_strtrim(char *line);
char	*get_next_line(int fd);
int		ft_strlen(char *str);
void	*ft_memcpy(void	*dest, const void *src, size_t n);

#endif
