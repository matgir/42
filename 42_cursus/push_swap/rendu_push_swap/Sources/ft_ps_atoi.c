/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:41:08 by mgirardo          #+#    #+#             */
/*   Updated: 2021/12/13 17:10:40 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

int	ft_ps_atoi(char *nptr, int *error)
{
	unsigned long	i;
	int				sign;
	long int		nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while ((nptr[i] >= '0' && nptr[i] <= '9'))
	{
		nbr = nbr * 10 + (nptr[i] - 48);
		i++;
		*error = 1;
	}
	if (nbr * sign >= 2147483647 || nbr * sign <= -2147483648)
		*error = 2;
	return (nbr * sign);
}
