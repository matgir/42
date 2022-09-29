/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:20:22 by mgirardo          #+#    #+#             */
/*   Updated: 2022/09/29 15:20:24 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libphilo.h"

int	digit_check(char *str)
{
	
}

int	parsing_philo(int argc, char **argv)
{
	unsigned int	i;

	if (argc < 5 || argc > 6)
		return (1);
	i = 0;
	while (++i < argc)
	{
		if (!digit_check(argv[i]))
			return (/* to be determine */);
	}
}

int	main(int argc, char **argv)
{
	t_omniscient	*god;

	god = NULL;
	if (!parsing_philo(argc, argv));
		return (/* to be determine */);
}