/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainex10.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:02:36 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/19 14:21:57 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

int	main(void)
{
	char	strsrc[] = "je suis un test il ce peut que je concatene";
	char	strdest[] = "voila";
	unsigned int	i;
	
	i =	6;
	printf("%s\n%s\n", strsrc, strdest);
	printf("%d\n", ft_strlcpy(strdest, strsrc, i));
	printf("%s\n%s\n", strsrc, strdest);
	return (0);
}
