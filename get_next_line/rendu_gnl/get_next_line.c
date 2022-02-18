/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 10:56:36 by mgirardo          #+#    #+#             */
/*   Updated: 2022/02/10 16:18:17 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_gnl_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	l;

	l = ft_gnl_strlen(src);
	if (size > 0)
	{
		i = 0;
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (l);
}

char	*ft_gnl_strjoin(char *line, char *buffer)
{
	char	*join;
	size_t	i;
	size_t	j;

	i = ft_gnl_strlen(line);
	j = ft_gnl_strlen(buffer);
	join = malloc(sizeof(char) * (i + j + 1));
	if (join == NULL)
		return (NULL);
	ft_gnl_strlcpy((ft_memcpy(join, line, i) + i), buffer, (j + 1));
	free(line);
	return (join);
}

int	ft_gnl_strchr(const char *buffer)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_gnl_strlen(buffer);
	while (i < j)
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	buf[BUFFER_SIZE + 1];
	int			end;

	if (BUFFER_SIZE < 1 || read(fd, NULL, 0) == -1)
		return (NULL);
	line = NULL;
	while (ft_gnl_strchr(buf) == -1)
	{
		line = ft_gnl_strjoin(line, buf);
		if (line == NULL)
			return (NULL);
		end = read(fd, buf, BUFFER_SIZE);
		buf[end] = '\0';
		if (end == 0 && line[0] == '\0')
		{
			free(line);
			return (NULL);
		}
		else if (end == 0)
			return (line);
	}
	line = ft_gnl_strjoin(line, buf);
	ft_gnl_strlcpy(buf, buf + ft_gnl_strlen(buf), BUFFER_SIZE);
	return (line);
}
