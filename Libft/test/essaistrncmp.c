/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   essaistrncmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:19:50 by mgirardo          #+#    #+#             */
/*   Updated: 2021/12/08 15:34:07 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	while (n-- != 0)
	{
		if (*((unsigned char *) s1++) != *((unsigned char *) s2++))
			break;
	}
	return (*((unsigned char *) --s1) - *((unsigned char *) --s2));
}


#include <stdio.h>
#include <string.h>

int main(void)
{
	
	char	s1[] = "bonsoir je suis un A";
	char	s2[] = "bonsour je suis un A";
	unsigned int 	n = 12;

	printf("%d\n", ft_strncmp(s1, s2, n));
	printf("%d", strncmp(s1, s2, n));
	return (0);
}

