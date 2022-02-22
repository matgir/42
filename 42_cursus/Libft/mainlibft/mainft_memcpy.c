/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainft_memcpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:22:28 by mgirardo          #+#    #+#             */
/*   Updated: 2021/12/13 14:21:19 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stddef.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n);

int	main(void)
{
	char		dest2[] = "bonjour a vous";
	const char	src2[] = "Bonsoir de vous et de lui";
	size_t		n;
	
	n = 12;
	printf("%s\n", dest2);
	printf("%p\n", dest2);
	printf("%p\n", ft_memcpy(dest2, src2, n));
	printf("%s\n", dest2);
	return (0);
}
