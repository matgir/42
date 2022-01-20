/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:22:06 by mgirardo          #+#    #+#             */
/*   Updated: 2022/01/20 11:57:16 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftptf.h"

int	ft_puthex(unsigned int n)
{
	unsigned int	ntmp;
	int				i;
	char			*str;
	char			*hexbase;

	i = 1;
	ntmp = n;
	while (n / 16 != 0)
	{
		n = n / 16;
		i++;
	}
	hexbase = "0123456789abcdef";
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
