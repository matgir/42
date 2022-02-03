/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:58:00 by mgirardo          #+#    #+#             */
/*   Updated: 2022/02/03 17:52:22 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int	main()
{
	int fd;
	char	str[10];

	fd = open("numbers.dict.txt", O_RDONLY);
	while (1)
	{
		read(fd, str, 10);
		if (strcmp(str, "decillion\n") == 0)
		{
			printf("END OF READ\n");
			break;
		}
		printf("%s\n", str);
		printf("%i\n", fd);
		//free(str);
	}
	close(fd);
	return (0);
}
