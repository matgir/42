/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:30:10 by itahani           #+#    #+#             */
/*   Updated: 2021/12/01 09:09:22 by itahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (c == '\0')
	{
		while ((unsigned const char *)(s + i))
		{
			if (s[i] == (unsigned char)c)
				return ((char *)(s + i));
			i++;
		}
	}
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)(s + i));
		i++;
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>
int main()
{
	void *m = ft_strchr("ther\0is\0\0 so", '\0');
	void *n = strchr("ther\0is\0\0 so", '\0');
	if (n == m)
		printf("OK  ");
	else	
		printf("KO  ");
	printf("ft_ : ");	
	if (m)
		printf("Hello  |");
	else
		printf("Pas Hello  |");

	printf("strchr : ");
	if (n)
		printf("Hello\n");
	else
		printf("Pas Hello\n");
}*/
