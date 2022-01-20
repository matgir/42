/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:22:06 by mgirardo          #+#    #+#             */
/*   Updated: 2022/01/20 16:52:24 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_puthex(unsigned int n, char *hexbase)
{
	unsigned int	ntmp;
	int				i;
	char			*str;

	i = 1;
	ntmp = n;
	while (n / 16 != 0)
	{
		n = n / 16;
		i++;
	}
	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (0);
	str[i] = '\0';
	while (--i >= 0)
	{
		str[i] = hexbase[ntmp % 16];
		ntmp /= 16;
	}
	ft_putstr(str);
	return (ft_strlen(str));
}
