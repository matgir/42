/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:26:24 by itahani           #+#    #+#             */
/*   Updated: 2022/03/17 18:26:29 by itahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "libft.h"

int	gnl_strchr(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		return (i);
	return (-1);
}

int	gnl_strlen(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*gnl_strdup(char *line)
{
	char	*cpy;
	int		i;

	i = 0;
	cpy = malloc(sizeof (char) * gnl_strlen(line) + 1);
	if (!cpy)
		return (NULL);
	while (line && line[i])
	{
		cpy[i] = line[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*gnl_strjoin(char *line, char *to_add)
{
	int		i;
	int		j;
	char	*line_t;

	i = -1;
	j = 0;
	line_t = gnl_strdup(line);
	free(line);
	line = malloc(sizeof (char)
			* ((gnl_strlen(to_add)) + gnl_strlen(line_t) + 1));
	if (!line)
		return (NULL);
	line[gnl_strlen(line_t) + gnl_strlen(to_add)] = '\0';
	if (line_t == NULL)
		return (NULL);
	while (line_t && line_t[++i])
		line[i] = line_t[i];
	while (line && to_add && to_add[j])
	{
		line[i] = to_add[j];
		i++;
		j++;
	}
	free(line_t);
	return (line);
}
