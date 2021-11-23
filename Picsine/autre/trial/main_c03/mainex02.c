/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainex02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 21:24:07 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/19 10:06:07 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strcat(char *dest, char *src);

int	main(void)
{
	char	src[] = " je suis la suite";
	char	dest[100] = "la voila";
	char	srce[] = " je suis la suite";
	char	dst[100] = "la voila";

	printf("%s   %s\n\n", src, dest);
	printf("%s   %s\n\n", src, ft_strcat(dest, src));
	printf("%s   %s\n\n", srce, dst);
	printf("%s   %s\n\n", srce, strcat(dst, srce));
	return (0);
}
