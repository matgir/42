/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 10:56:36 by mgirardo          #+#    #+#             */
/*   Updated: 2022/02/08 17:56:15 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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

/*void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*tmp;
	size_t	i;

	tmp = (char *)src;
	i = 0;
	if (dest > src)
	{
		while (n--)
			((char *)dest)[n] = tmp[n];
	}
	else
	{
		while (i < n)
		{
			((char *)dest)[i] = tmp[i];
			i++;
		}
	}
	return (dest);
}*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{

	size_t	i	;

	i = 0;
	while (n != 0)
	{
		((unsigned char *) dest)[i] = ((unsigned const char *) src)[i];
		i++;
		n--;
	}
	return (dest);
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

	line = malloc(sizeof(char) * 1);
	if (line == NULL)
		return (NULL);
	line[0] = '\0';
//	if (buffer[0] == '\0')
//		buffer[read(fd, buffer, BUFFER_SIZE)] = '\0';
	while (ft_strchr(buffer, '\n') == -1)
	{
	//	printf("line = %s.", line);
		buffer[read(fd, buffer, BUFFER_SIZE)] = '\0';
		line = ft_strjoin(line, buffer);
	}
//	printf("buffer = %s.", buffer);
	line = ft_strjoin(line, buffer);
	line = ft_strtrim(line);
	ft_strlcpy(buffer, buffer + ft_strchr(buffer, '\n') + 1, BUFFER_SIZE);
	return (line);
}
