/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 10:56:36 by mgirardo          #+#    #+#             */
/*   Updated: 2022/02/09 16:19:02 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlcpy(char *line, char *buffer, size_t size)
{
	size_t	i;
	size_t	j;

	j = ft_strlen(buffer);
	if (size > 0)
	{
		i = 0;
		while (buffer[i] && i < size - 1)
		{
			line[i] = buffer[i];
			i++;
		}
		line[i] = '\0';
	}
	return (j);
}

char	*ft_strjoin(char *line, char *buffer)
{
	char	*join;
	size_t	i;
	size_t	j;

	i = ft_strlen(line);
	j = ft_strlen(buffer);
	join = malloc(sizeof(char) * (i + j + 1));
	if (join == NULL)
		return (NULL);
	ft_strlcpy((ft_memcpy(join, line, i) + i), buffer, (j + 1));
	free(line);
	return (join);
}

int	ft_strchr(char *buffer, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(buffer);
	while (i < j)
	{
		if (buffer[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strtrim(char *line)
{
	int		size;
	char	*strtrim;

	size = 0;
	while (line[size] && line[size] != '\n')
		size++;
	strtrim = malloc(sizeof(char) * size + 2);
	if (strtrim == NULL)
		return (NULL);
	ft_strlcpy(strtrim, line, size + 2);
	free(line);
	return (strtrim);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	buf[1024][BUFFER_SIZE + 1];
	int			end;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, NULL, 0) == -1)
		return (NULL);
	line = malloc(sizeof(char) * 1);
	if (line == NULL)
		return (NULL);
	line[0] = '\0';
	while (ft_strchr(buf[fd], '\n') == -1)
	{
		line = ft_strjoin(line, buf[fd]);
		end = read(fd, buf[fd], BUFFER_SIZE);
		buf[fd][end] = '\0';
		if (end == 0 && line[0] == '\0')
		{
			free(line);
			return (NULL);
		}
		else if (end == 0)
			return (line);
	}
	return (final_line(line, buf[fd]));
}
