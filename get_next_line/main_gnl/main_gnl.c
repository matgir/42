/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:58:00 by mgirardo          #+#    #+#             */
/*   Updated: 2022/02/08 17:45:13 by mgirardo         ###   ########.fr       */
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

	fd = open("numbers.dict.txt", O_RDONLY);
//	fd = 1;
	int i = 0;
	while (i++ < 41)
		printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}
