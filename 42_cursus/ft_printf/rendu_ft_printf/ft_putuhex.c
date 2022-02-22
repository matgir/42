/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuhex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 14:29:01 by mgirardo          #+#    #+#             */
/*   Updated: 2022/01/20 16:53:55 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putuhex(unsigned long int uli, char *hexbase)
{
	unsigned long int	ntmp;
	int					i;
	char				*str;
	int					len;

	i = 1;
	ntmp = uli;
	while (uli / 16 != 0)
	{
		uli = uli / 16;
		i++;
	}
	len = i;
	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (0);
	str[i] = '\0';
	while (--i >= 0)
	{
		str[i] = hexbase[ntmp % 16];
		ntmp /= 16;
	}
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}
