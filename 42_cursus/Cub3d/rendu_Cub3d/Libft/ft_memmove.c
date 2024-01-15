/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:43:10 by itahani           #+#    #+#             */
/*   Updated: 2021/12/01 09:53:49 by itahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned int	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	if (dst > src)
	{
		while (n > 0)
		{
			n--;
			*(char *)(dst + n) = *(const char *)(src + n);
		}
	}
	else
	{
		while (i < n)
		{
			*(char *)(dst + i) = *(const char *)(src + i);
			i++;
		}
	}
	return (dst);
}
/*#include <stdio.h>
#include <stdlib.h>

int	main()
{
	char s[] = "Bonjour";
	char d[] = "Hello";
	printf("%s\n", ft_memmove(d, s, 3));

	char dmove[] = "Hello";
	char smove[] = "Bonjour";
	printf("%s\n", memmove(dmove, smove, 3));
}*/
