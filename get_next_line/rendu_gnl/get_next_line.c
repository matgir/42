/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 10:56:36 by mgirardo          #+#    #+#             */
/*   Updated: 2022/02/09 10:23:17 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	buffer[BUFFER_SIZE + 1];
	int			end;

	line = malloc(sizeof(char) * 1);
	if (line == NULL)
		return (NULL);
	line[0] = '\0';
	while (ft_strchr(buffer, '\n') == -1)
	{
		line = ft_strjoin(line, buffer);
		end = read(fd, buffer, BUFFER_SIZE);
		if (end == 0)
			return (NULL);
		buffer[end] = '\0';
	}
	line = ft_strjoin(line, buffer);
	line = ft_strtrim(line);
	ft_strlcpy(buffer, buffer + ft_strchr(buffer, '\n') + 1, BUFFER_SIZE);
	return (line);
}
