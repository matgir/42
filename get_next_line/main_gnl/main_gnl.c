/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:58:00 by mgirardo          #+#    #+#             */
/*   Updated: 2022/02/09 15:52:03 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"

int	main()
{
	int		fd;
	int		fd1;
	int		fd2;
	char	*line;
	char	*line1;
	char	*line2;

	fd = open("numbers.dict.txt", O_RDONLY);
//	printf("%i\n", fd);
	fd1 = open("numbers.dict.txt", O_RDONLY);
//	printf("%i\n", fd1);
	fd2 = open("test.file", O_RDONLY);
//	fd2 = 1;
	printf("%i\n", fd2);
	while (1)
	{
		/*line = get_next_line(fd);
		if (line == NULL)
			break;
		printf("%s", line);
		free(line);
		line1 = get_next_line(fd1);
		if (line1 == NULL)
			break;
		printf("%s", line1);
		free(line1);*/
		line2 = get_next_line(fd2);
		if (line2 == NULL)
			break;
		printf("%s", line2);
		free(line2);
	}
	close(fd);
	return (0);
}
