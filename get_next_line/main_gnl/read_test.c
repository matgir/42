/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:58:00 by mgirardo          #+#    #+#             */
/*   Updated: 2022/02/07 18:38:27 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


//		char	*get_net_line(int fd)


/*size_t	ft_strlcpy(char *dest, static char *str, size_t lenstr)
  {
  size_t	i;
  size_t	l;

  l = ft_strlen(src);
  if (size > 0)
  {
  i = 0;
  while (str[i] && i < lenstr - 1)
  {
  dest[i] = str[i];
  i++;
  }
  dest[i] = '\0'
  }
  return (l)
  }*/

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

int	main()
{
	int			fd;
	char		*ligne;
	static char		buffer[10];

	fd = open("numbers.dict.txt", O_RDONLY);
//	read(fd, buffer, 10);

	//		DEBUT GNL

	ligne = malloc(sizeof(char) * 0);
	if (buffer[0] == '\0')
	{
		read(fd, buffer, 10);
		while (ft_strchr(buffer) == -1)
		{
			ligne = ft_strjoin(ligne, buffer);
			read(fd, buffer, 10);
		}
		ligne = ft_strjoin(ligne, buffer);
// faire fonction qui trime a partir de \n + 1 puis put str
	}
/*	else
	{
		ligne = ft_strjoin(ligne, ft_substr(buffer, ))
	
		
	}*/

	// 		FIN GNL

	printf("%s\n", ligne);
	printf("%s\n", buffer);
	close(fd);
	return (0);
}
