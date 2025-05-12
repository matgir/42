/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainex01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:45:51 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/12 12:46:11 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strncpy(char	*dest, 	char	*src, unsigned int	n);

int main(void)
{
    char    str1[] = "1098";
    char    str2[] = "012345678910";
	unsigned int	n;

	n = 24;
    printf("%s\n", str1);
    printf("%s\n", str2);
    ft_strncpy(str2, str1, n);
    printf("%s\n", str1);
    printf("%s\n", str2);
    /*strncpy(str2, str1, n);
    printf("%s\n", str1);
    printf("%s\n", str2);*/
    return (0);
}
