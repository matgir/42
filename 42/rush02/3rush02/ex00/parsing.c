/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 16:34:28 by llepiney          #+#    #+#             */
/*   Updated: 2021/08/22 21:58:56 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
int	ft_parsing(char *txt, char *key)
{
	char	*buffer;
	int	i;
	char	*chepa;
	int	fd;

	chepa = txt;
	fd = open(chepa, O_RDONLY);
	buffer = malloc(sizeof(char) * 1);
	i = 0;
	(read(fd, &*buffer, 1));

	while (*buffer == key[i])
	{
		read(fd, &*buffer, 1);
		i++;
	}
	while (read(fd, &*buffer, 1))
	{
		if (*buffer == '\n')
		{
			read(fd, &*buffer, 1);
			while (*buffer == key[i])
			{
				read(fd, &*buffer, 1);
				i++;
			}
		}
		if (!key[i] && !(*buffer >= '0' && *buffer <= '9'))
		{
			while (*buffer == ' ')
				read(fd, &*buffer, 1);
			if (*buffer == ':')
				read(fd, &*buffer, 1);
			while (*buffer == ' ')
				read(fd, &*buffer, 1);
			while (*buffer != '\n' && *buffer)
			{
				write(1, &*buffer, 1);
				read(fd, &*buffer, 1);
			}
		}
		i = 0;
	}
	close(fd);
	return (1);
}
