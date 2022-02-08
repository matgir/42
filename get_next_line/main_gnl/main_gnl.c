/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:58:00 by mgirardo          #+#    #+#             */
/*   Updated: 2022/02/08 11:21:30 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char	*get_next_line(int fd);

int	main()
{
	int				fd;
	char			*line;

	fd = open("numbers.dict.txt", O_RDONLY);
//	read(fd, buffer, 10);
	line = get_next_line(fd);
	printf("%s\n", line);
	close(fd);
	return (0);
}
