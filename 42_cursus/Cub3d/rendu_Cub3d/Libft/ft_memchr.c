/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:26:47 by itahani           #+#    #+#             */
/*   Updated: 2021/11/30 17:26:30 by itahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	long unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s + i) == (unsigned char)c)
			return ((unsigned char *)(s + i));
		i++;
	}
	return (NULL);
}
/*
int main()
{
	void *m = ft_memchr("/|\x12\xff\x09\0\x42\042\0\42|\\", '\0', 12);
	void *n = memchr("/|\x12\xff\x09\0\x42\042\0\42|\\", '\0', 12);
	if (n == m)
		printf("OK  ");
	else	
		printf("KO  ");
	printf("ft_ : ");	
	if (m)
		printf("Hello  |");
	else
		printf("Pas Hello  |");

	printf("memchr : ");
	if (n)
		printf("Hello\n");
	else
		printf("Pas Hello\n");

}*/
