/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainmemcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:47:44 by mgirardo          #+#    #+#             */
/*   Updated: 2021/11/25 16:37:35 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stddef.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n);

int	main(void)
{
	char		s[] = "bonjour a vous";
	char		l[] = "bonjour a vous";
	const char	c[] = "Bonsoir a vous";
	size_t		n;
	
	c = 65;
	n = 8;
	printf("%s\n", s);
	ft_memset(s, c, n);
	printf("%s\n", s);
	
	c = 65;
	n = 8;
	printf("%s\n", l);
	memset(l, c, n);
	printf("%s\n", l);
	
	return (0);
}
