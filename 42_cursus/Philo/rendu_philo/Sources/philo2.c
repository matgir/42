/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:20:22 by mgirardo          #+#    #+#             */
/*   Updated: 2022/09/29 18:35:43 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libphilo.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_omniscient	*god;

	god = NULL;
	if (!parsing_philo(argc, argv))
		return (printf("Wrong arguments\n"));
	god = init(argc, argv, 0);
	if (god == NULL)
		return (0);
	/* start simulation */
	return (1);
}
