/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:34:06 by mgirardo          #+#    #+#             */
/*   Updated: 2022/01/04 16:28:51 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_du_turfu.h"

static char	*ft_sign(long int ntmp, int i, char *str)
{
	if (ntmp < 0)
	{
		ntmp *= -1;
		str[0] = '-';
		str[i] = '\0';
		while (--i > 0)
		{
			str[i] = ntmp % 10 + 48;
			ntmp /= 10;
		}
	}
	else
	{
		str[i] = '\0';
		while (--i >= 0)
		{
			str[i] = ntmp % 10 + 48;
			ntmp /= 10;
		}
	}
	return (str);
}

char	*ft_itoa(int n)
{
	long int	ntmp;
	int			i;
	char		*str;

	i = 1;
	ntmp = n;
	while (n / 10 != 0)
	{	
		n = n / 10;
		i++;
	}
	if (ntmp < 0)
		str = malloc(sizeof(char) * (++i + 1));
	else
		str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	return (ft_sign(ntmp, i, str));
}
