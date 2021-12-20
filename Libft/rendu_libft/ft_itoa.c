/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:34:06 by mgirardo          #+#    #+#             */
/*   Updated: 2021/12/20 11:06:25 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

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
	if (ntmp < 0)
	{
		ntmp = ntmp * -1;
		i++;
		str = malloc(sizeof(char) * (i + 1));
		str[0] = '-';
		str[i + 1] = '\0';
		while (i > 0)
		{
			str[i] = ntmp%10 + 48;
			ntmp = ntmp/10 + 48;
			i--;
		}
	}
	else
	{
		str = malloc(sizeof(char) * (i + 1));
		str[i + 1] = '\0';
		while (i >= 0)
		{
			str[i] = ntmp%10 + 48;
			ntmp = ntmp/10 + 48;;
			i--;
		}
	}
	return (str);
}
