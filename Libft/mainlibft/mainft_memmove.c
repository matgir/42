/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainft_memmove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:23:19 by mgirardo          #+#    #+#             */
/*   Updated: 2021/12/08 15:07:01 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

void	ft_memmove(void *dest, const void *src, size_t n);

int	main()\
{
	char		dest[] = "bonsoir";
	const char	src[] = "hello hello";
	size_t		n = 75;

	printf("%s\n", dest); ft_memmove(dest,src,n); printf("%s\n", dest);
	//printf("%s\n", dest); memmove(dest,src,n); printf("%s\n", dest);
}
