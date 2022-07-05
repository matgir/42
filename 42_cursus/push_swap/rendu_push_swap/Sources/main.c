/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:26:46 by mgirardo          #+#    #+#             */
/*   Updated: 2022/07/05 11:26:58 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

int	ft_ps_intcheck(char **av)
{
	int	i;
	int	error;

	i = 0;
	while (av[++i])
	{
		error = 0;
		ft_ps_atoi(av[i], &error);
		if (error != 1)
		{
			ft_putendl_fd("Error not int", 2);
			return(0);
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
				ft_putendl_fd("Error duplicate", 2);
				return(0);
			}
		}
	}
	return (1);
}

int	ft_ps_parsing(int ac, char **av)
{
	if (ac < 2)
	{
		ft_putendl_fd("Error param", 2);
		return (0);
	}
	if (ft_ps_intcheck(av) == 0)
		return (0);
	if (ft_ps_duplicatecheck(av) == 0)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	if (ft_ps_parsing(ac, av) == 0)
		return (0);
}
