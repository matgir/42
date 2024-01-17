/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:38:25 by itahani           #+#    #+#             */
/*   Updated: 2021/12/02 16:20:35 by itahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	long unsigned int	i;
	char				*buffer;

	i = 0;
	buffer = (char *)s;
	while (i != n)
	{
		buffer[i] = c;
		i++;
	}
	return (s);
}
/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		int	n;
		n = atoi(argv[3]);
		printf("%s", "ft_memset : ");
		printf("%s\n", ft_memset(argv[1], argv[2][0], n));
		printf("%s", "memset : ");
		printf("%s\n", memset(argv[1], argv[2][0], n));
	}
}
*/
