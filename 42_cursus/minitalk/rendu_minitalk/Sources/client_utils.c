/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 16:57:39 by mgirardo          #+#    #+#             */
/*   Updated: 2022/08/04 16:57:43 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libminitalk.h"

int	ft_mntlk_atoi(char *nptr, int *error)
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
	if (nbr * sign > 2147483647 || nbr * sign <= 0)
		*error = 2;
	return (nbr * sign);
}

int	digit_check(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] != '-' && str[i] != '+')
		{
			if (ft_isdigit((int)str[i]) == 0)
				return (0);
		}
	}
	return (1);
}

int	ft_mntlk_intcheck(char *av)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	if (ft_strlen(av) > 11)
		error = 3;
	ft_mntlk_atoi(av, &error);
	if (digit_check(av) == 0)
		error = 4;
	if (error != 1)
		return (0);
	return (1);
}
