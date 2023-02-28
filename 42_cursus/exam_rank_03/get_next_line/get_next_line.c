/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:35:43 by mgirardo          #+#    #+#             */
/*   Updated: 2023/02/28 13:35:45 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_gnl_strlen(const char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

void	ft_gnl_strcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (size > 0)
	{
		i = 0;
		while (src[i] && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
}

char	*ft_gnl_strjoin(char *line, char *buf)
{
	char	*newline;
	size_t	i;
	size_t	j;
	size_t	k;

	i = ft_gnl_strlen(line);
	j = ft_gnl_strlen(buf);
	newline = malloc(sizeof(char) * (i + j + 1));
	if (!newline)
		return (NULL);
	k = 0;
	while (i != 0)
	{
		newline[k] = line[k];
		i--;
		k++;
	}
	while (j-- != 0)
		newline[k++] = buf[i++];
	newline[k] = '\0';
	free(line);
	return (newline);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	int			end;

	if (BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	while (buf[ft_gnl_strlen(buf) - 1] != '\n')
	{
		line = ft_gnl_strjoin(line, buf);
		if (!line)
			return (NULL);
		end = read(fd, buf, BUFFER_SIZE);
		if (end == -1)
		{
			free(line);
			return (NULL);
		}
		buf[end] = '\0';
		if (end == 0 && line[0] == '\0')
		{
			free(line);
			return (NULL);
		}
		if (end == 0)
			return (NULL);
	}
	line = ft_gnl_strjoin(line, buf);
	if (!line) /* peut etre free la line qui est rentrer dans le join precedent */
		return (NULL);
	ft_gnl_strcpy(buf, buf + ft_gnl_strlen(buf), BUFFER_SIZE);
	return (line);
}