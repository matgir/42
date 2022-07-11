/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:41:08 by mgirardo          #+#    #+#             */
/*   Updated: 2022/07/05 12:52:48 by mgirardo         ###   ########.fr       */
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
	if (nbr * sign > 2147483647 || nbr * sign < -2147483648)
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

int	ft_ps_intcheck(char **av)
{
	int	i;
	int	error;

	i = 0;
	while (av[++i])
	{
		error = 0;
		if (ft_strlen(av[i]) > 11)
			error = 3;
		ft_ps_atoi(av[i], &error);
		if (digit_check(av[i]) == 0)
			error = 4;
		if (error != 1)
		{
			ft_putendl_fd("Error not int", 2);

ft_printf("error is %i\n", error);

			return (0);
		}
	}
	return (1);
}

int	ft_ps_duplicatecheck(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[++i])
	{	
		j = i;
		while (av[++j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
			{
				ft_putendl_fd("Error dup", 2);
				return (0);
			}
		}
	}
	return (1);
}

int	ft_ps_parsing(int ac, char **av)
{
	if (ac < 2)
		return (0);
	if (ft_ps_intcheck(av) == 0)
		return (0);
	if (ft_ps_duplicatecheck(av) == 0)
		return (0);
	if (ac == 2)
		return (0);
	return (1);
}
