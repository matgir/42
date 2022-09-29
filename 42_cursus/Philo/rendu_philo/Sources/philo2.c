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
#include <stdio.h>

t_omniscient	*init(int argc, char **argv, int i)
{
	
}

int	main(int argc, char **argv)
{
	t_omniscient	*god;

	god = NULL;
	if (!parsing_philo(argc, argv))
		return (printf("Wrong arguments\n"));
	god = init(argc, argv, 1);
	return (0);
}