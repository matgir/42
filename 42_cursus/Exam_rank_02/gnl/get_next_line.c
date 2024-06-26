#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

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

// char	*ft_gnl_strcpy(char *dest, const char *src, size_t size)
void	ft_gnl_strlcpy(char *dst, const char *src, size_t size)
{
	// int	i;
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
	// return (dest);
}

char	*ft_gnl_strjoin(char *line, char *buffer)
{
	char	*join;
	// int	i;
	size_t	i;
	// int	j;
	size_t	j;
	// int	k;
	size_t	u;

	i = ft_gnl_strlen(line);
	j = ft_gnl_strlen(buffer);
	join = malloc(sizeof(char) * (i + j + 1));
	if (join == NULL)
		return (NULL);
	u = 0;
	// while (i > 0)
	while (i != 0)
	{
		join[u] = line[u];
		u++;
		i--;
	}
	// while (j-- > 0)
	while (j-- != 0)
		join[u++] = buffer[i++];
	join[u] = '\0';
	free(line);
	return (join);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	buf[2];
	int			end;

	// if (BUFFER_SIZE < 1)
	if (BUFFER_SIZE < 1 || read(fd, NULL, 0) == -1)
		return (NULL);
	line = NULL;
	while (buf[ft_gnl_strlen(buf) - 1] != '\n' )
	{
		line = ft_gnl_strjoin(line, buf);
		if (line == NULL)
			return (NULL);
		end = read(fd, buf, 1);
		// if (end == -1)
		// {
			// free(line);
			// return (NULL);
		// }
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
	// if (!line) /* peut etre free la line qui est rentrer dans le join precedent */
		// return (NULL);
	ft_gnl_strlcpy(buf, buf + ft_gnl_strlen(buf), 1);
	return (line);
}
