/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:26:11 by itahani           #+#    #+#             */
/*   Updated: 2022/03/17 18:26:16 by itahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

char	*save_until_cr(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	line[i] = '\0';
	return (line);
}

void	save_after_cr(char *buf)
{
	int	i;
	int	j;

	i = 0;
	j = gnl_strchr(buf) + 1;
	while (buf[j])
	{
		buf[i] = buf[j];
		i++;
		j++;
	}
	buf[i] = '\0';
}

char	*check_line(char **line, int fin)
{
	if ((*line) == NULL)
		return (NULL);
	if (fin == 0 && line[0][0] == '\0')
	{
		free(*line);
		*line = NULL;
		return (NULL);
	}
	else if (fin == 0)
		return (*line);
	return ("no check");
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	buf[BUFFER_SIZE + 1] = "";
	int			fin;

	line = NULL;
	fin = -1;
	if (BUFFER_SIZE <= 0 || read(fd, NULL, 0) == -1)
		return (NULL);
	if (buf[0] != '\0')
		line = gnl_strjoin(line, buf);
	while (((line == NULL) && fin != 0)
		|| ((gnl_strchr(buf) == -1 && fin != 0)))
	{
		fin = read(fd, buf, BUFFER_SIZE);
		buf[fin] = '\0';
		line = gnl_strjoin(line, buf);
	}
	if (check_line(&line, fin) == NULL || check_line(&line, fin) == line)
		return (check_line(&line, fin));
	line = save_until_cr(line);
	save_after_cr(buf);
	return (line);
}
