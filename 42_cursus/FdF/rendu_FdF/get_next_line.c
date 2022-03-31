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
						needeed to declare its value in the function itself, or
						compile with "-D BUFFER_SIZE=42")

		void	ft_gnl_strlcpy(char *dst, const char *src, size_t size);
		char	*ft_gnl_strjoin(char *line, char *buffer);
		char	*get_next_line(int fd);
		int		ft_gnl_strlen(const char *str);

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
		The only difference with de classical strlcpy is the fact that it does
		not send back the len of src
*/

char	*ft_gnl_strjoin(char *line, char *buffer)
{
	char	*join;
	size_t	i;
	size_t	j;
	size_t	u;

	i = ft_gnl_strlen(line);
	j = ft_gnl_strlen(buffer);
	join = malloc(sizeof(char) * (i + j + 1));
	if (join == NULL)
		return (NULL);
	u = 0;
	while (i != 0)
	{
		join[u] = line[u];
		u++;
		i--;
	}
	while (j-- != 0)
		join[u++] = buffer[i++];
	join[u] = '\0';
	free(line);
	return (join);
}

/*
		This strjoin uses ft_gnl_strlen and also frees line that was previously
		malloced in the main function, so that there isn't any leaks, even with
		the first call where line = NULL it ain't a problem because you can free
		a NULL str
		The way to join line and buffer is the same as in memcpy
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

/*
		-	In this get next line you can deal with multiple fdwithout intertwin
			the with eatchother hence the [1024] create a char **buf
		-	The first if allows you to check the size of BUFFER_SIZE, because if
			it is under 1 then you won't read anything.
			It also check if the fd is right because if read return -1 then it
			means that fd hasn't opened anything so there is nothing to read
		-	You can set line at NULL thanks to the customised ft_gnl_strlen that
			wont segfault in the strjoin
		-	In the while conditions you can check whether there is a '\n' in buf
			once again thanks to the customized ft_gnl_strlen that returns where
			the '\n' is + 1, hence the '-1'
		-	If ther isn't a '\n' in buf then NULL line and my NULL buf are
			joined that giving an empty line with only a '\0' in it
			When buf already has something in it as it is a static then NULL
			line and buf are joined to obtain the beginning of the newline
		-	The line == NULL check if the malloc in the join just before worked
			because if it doesn't then the program would segfault later when
			the program compare NULL line with a '\0'
		-	The result of read goes in end (how many character did it read)
			because it will be needed for :
			-	putting the '\0' at the end of buf alowing the program to
				manipulate it as a classical string
			-	knowing if it has finished reading the file if it is equal to 0,
				then it will just return the line, but if it's combined with an
				empty line it means that it has finished reading and that there
				isn't anything left to send back, so it frees the earlier
				maloced line and return NULL
		-	If there is a '\n' in buf then it join line and buf until the '\n'
			in buf thanks to the customised ft_gnl_strlen
		-	With strlcpy it copys buf after the '\n' in buf so that i can use
			buf properly for the next call of the function as buf is static
*/
