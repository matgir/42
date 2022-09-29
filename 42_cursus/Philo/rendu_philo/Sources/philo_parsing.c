/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:37:57 by mgirardo          #+#    #+#             */
/*   Updated: 2022/09/29 18:37:58 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isdigit(int c)
{
	if (c < '0' || c > '9')
		return (0);
	else
		return (2048);
}

int	digit_check(char *str)
{
	unsigned int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit((int)str[i]))
			return (0);
	}
	return (1);
}

int	atoi_philo(char	*str)
{
	size_t		i;
	long int	nbr;

	nbr = 0;
	i = 0;
	while (str[i])
	{
		nbr = nbr * 10 + (str[i] - 48);
		i++;
	}
	if (nbr < 0 || nbr > 2147483647)
		nbr = -1;
	return (nbr);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	parsing_philo(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
		return (0);
	i = 0;
	while (++i < argc)
	{
		if (!digit_check(argv[i]))
			return (0);
		if (ft_strlen(argv[i]) > 10)
			return (0);
		if (atoi_philo(argv[i]) == -1)
			return (0);
/* 		if (i == 1 && atoi_philo(argv[i]) > 200)
			return (1); */
	}
	return (1);
}
