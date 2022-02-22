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

/*
		In order to use it everywhere :
		include your own .h as follow

		#ifndef NOM_LIB_H
		# define NOM_LIB_H

		# include <stddef.h>
		# include <stdlib.h>
		# include <unistd.h>

		# define BUFFER_SIZE 42
						(to be changed as wanted, 1 will take longer to
						execute, in betwen 50 and 100 should be good, may be
						needeed to declare its value in the fnction itself)

		void	ft_gnl_strlcpy(char *dst, const char *src, size_t size);
		char	*ft_gnl_strjoin(char *line, char *buffer);
		int		ft_gnl_strchr(const char *buffer);
		char	*get_next_line(int fd);
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

/*
		Special strlen for gnl : 
		-	allows you to assign NULL to the line created in the main function
		-	when you send it the buffer, in strjoin, with the '\n' in it it'll
			send back de size with de '\n' and nothing more, so there is no
			need to trim your line afterwards
*/

void	ft_gnl_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

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
}

/*
		The only difference with de classical strlcpy is the fact does not sent
		back the len of src
*/

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

/*
		This strjoin uses ft_gnl_strlen and also frees line that was previously
		malloced in the main function, so that there isn't any leaks
*/

char	*get_next_line(int fd)
{
	char		*line;
	static char	buf[BUFFER_SIZE + 1];
	int			end;

	if (BUFFER_SIZE < 1 || read(fd, NULL, 0) == -1)
		return (NULL);
	line = NULL;
	while (buf[ft_gnl_strlen(buf) - 1] != '\n' )
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
