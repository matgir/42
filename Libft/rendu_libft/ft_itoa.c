/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:34:06 by mgirardo          #+#    #+#             */
/*   Updated: 2021/12/20 11:26:22 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char	*ft_itoa(int n)
{
	long int	ntmp;
	int			i;
	char		*str;

	i = 1;
	ntmp = n;
	while (n/10 != 0)
	{	
		n = n/10;
		i++;
	}
	str = malloc(sizeof(char) * (i + 1));
	str[i] = '\0';
	while (--i >= 0)
	{
		str[i] = ntmp%10 + 48;
		ntmp = ntmp/10;
	}
	if (n < 0)
		str = ft_strjoin("-", str);
	return (str);
}
