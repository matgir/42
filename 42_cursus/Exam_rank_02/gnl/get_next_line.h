/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:35:50 by mgirardo          #+#    #+#             */
/*   Updated: 2023/02/28 13:35:51 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

int		ft_gnl_strlen(char *str);
void	ft_gnl_strcpy(char *dest, const char *src, size_t size);
char	*ft_gnl_strjoin(char *line, char *buf);
char	*get_next_line(int fd);

#endif