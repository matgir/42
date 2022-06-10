/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_gnl_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:36:03 by mgirardo          #+#    #+#             */
/*   Updated: 2022/06/08 13:36:05 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

int	check_buf_n_fd(int fd, int *gnl_error)
{
	if (BUFFER_SIZE < 1 || read(fd, NULL, 0) == -1)
	{
		*gnl_error = -1;
		return (-1);
	}
	return (0);
}

int	check_line(char *line, int *gnl_error)
{
	if (line == NULL)
	{
		*gnl_error = -2;
		return (-1);
	}
	return (0);
}

int	check_end(int end, char *line, int *gnl_error)
{
	if (end == 0 && line[0] == '\0')
	{
		free(line);
		*gnl_error = -3;
		return (-1);
	}
	return (0);
}
