/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_multiple_fd.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 10:56:36 by mgirardo          #+#    #+#             */
/*   Updated: 2022/02/10 16:37:40 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*		In order to use it everywhere :
		include your own .h as follow

		#ifndef NOM_LIB_H
		# define NOM_LIB_H

		# include <stddef.h>
		# include <stdlib.h>
		# include <unistd.h>

		int BUFFER_SIZE = 42;	(to be changed as wanted, 1 will take longer to
								execute, in betwen 50 and 100 should be good)

		size_t	ft_gnl_strlcpy(char *dst, const char *src, size_t size);
		char	*ft_gnl_strjoin(char *line, char *buffer);
		int		ft_gnl_strchr(const char *buffer);
		char	*get_next_line_multiple_fd(int fd);
		int		ft_gnl_strlen(const char *str);
		void	*ft_memcpy(void	*dest, const void *src, size_t n);
								(don't forget to use it with the .c of memcpy)

		#endif
*/

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

char	*get_next_line_multiple_fd(int fd)
{
	char		*line;
	static char	buf[1024][BUFFER_SIZE + 1];
	int			end;

	if (BUFFER_SIZE < 1 || read(fd, NULL, 0) == -1)
		return (NULL);
	line = NULL;
	while (ft_gnl_strchr(buf[fd]) == -1)
	{
		line = ft_gnl_strjoin(line, buf[fd]);
		if (line == NULL)
			return (NULL);
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
	line = ft_gnl_strjoin(line, buf[fd]);
	ft_gnl_strlcpy(buf[fd], buf[fd] + ft_gnl_strlen(buf[fd]), BUFFER_SIZE);
	return (line);
}