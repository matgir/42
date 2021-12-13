/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainft_memset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:47:12 by mgirardo          #+#    #+#             */
/*   Updated: 2021/12/13 14:15:21 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stddef.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void	*ft_memset(void *s, int c, size_t n);

int	main(void)
{
	char	s[] = "bonjour a vous";
	char	l[] = "bonjour a vous";
	int	c;
	size_t	n;
	
	c = 65;
	n = 8;
	printf("%s\n", s);
	printf("%p\n", s);
	printf("%p\n", ft_memset(s, c, n));
	printf("%s\n", s);
	
	c = 65;
	n = 8;
	printf("%s\n", l);
	printf("%p\n", l);
	printf("%p\n", memset(l, c, n));
	printf("%s\n", l);
	
	return (0);
}
