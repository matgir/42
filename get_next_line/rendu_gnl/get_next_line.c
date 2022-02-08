/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 10:56:36 by mgirardo          #+#    #+#             */
/*   Updated: 2022/02/08 11:26:45 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

size_t	ft_strlcpy(char *ligne, char buffer[10], size_t size)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (buffer[j])
		j++;
	if (size > 0)
	{
		i = 0;
		while (buffer[i] && i < size - 1)
		{
			ligne[i] = buffer[i];
			i++;
		}
		ligne[i] = '\0';
	}
	return (j);
}


char	*ft_strduppimped(char *buffer)
{
	char	*strdup;
	size_t	lenstr;

	lenstr = 0;
	while (buffer[lenstr] && buffer[lenstr] != '\n')
		lenstr++;
	strdup = malloc(sizeof(char) * (lenstr + 1));
	if (strdup == NULL)
		return (NULL);
	ft_strlcpy(strdup, buffer, lenstr + 1);
	return (strdup);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
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
}


char	*ft_strjoin(char *ligne, char *buffer)
{
	char	*join;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (ligne[i])
		i++;
	while (buffer[j])
		j++;
	join = malloc(sizeof(char) * (i + j + 1));
	if (join == NULL)
		return (NULL);
	ft_strlcpy((ft_memmove(join, ligne, i) + i), buffer, (j + 1));
	free(ligne);
	return (join);
}

int	ft_strchr(char *buffer)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (buffer[j])
		j++;
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
	char		*ligne;
	static char	buffer[BUFFER_SIZE];

	ligne = malloc(sizeof(char) * 0);
	if (ligne == NULL)
		return (NULL);
	if (buffer[0] == '\0')
	{
		read(fd, buffer, BUFFER_SIZE);
		while (ft_strchr(buffer) == -1)
		{
			ligne = ft_strjoin(ligne, buffer);
			read(fd, buffer, BUFFER_SIZE);
		}
		ligne = ft_strjoin(ligne, buffer);
		// faire fonction qui trime a partir de \n + 1
	}
	/*else
	{
		ligne = ft_strjoin(ligne, buffer);
		//faire fonction qui trime le depart a partir de \n + 1
	}*/
	return (ligne);
}
