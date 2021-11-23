/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainex03.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 22:11:48 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/19 11:31:24 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb);

int	main(void)
{
	char	src[] = " je suis la suite";
	char	dest[100] = "hello";
	char	srce[] = " je suis la suite";
	char	dst[100] = "hello";
	unsigned int 	nb;
	
	nb = 9;
	printf("%s   %s\n\n", src, dest);
	printf("%s   %s\n\n", src, ft_strncat(dest, src, nb));
	printf("%s   %s\n\n", srce, dst);
	printf("%s   %s\n\n", srce, strncat(dst, srce, nb));
	return (0);
}
