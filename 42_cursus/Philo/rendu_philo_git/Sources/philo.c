/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:20:22 by mgirardo          #+#    #+#             */
/*   Updated: 2022/10/03 16:56:50 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libphilo.h"
	#include <stdio.h>

int	main(int argc, char **argv)
{
	t_omniscient	*god;

	god = NULL;
	if (!parsing_philo(argc, argv))
		return (printf("Wrong arguments\n"));
	god = init(argc, argv, 1);
	if (god == NULL)
		return (0);
	if (!start_meal(god, 0))
		return (free_god_almighty(god, god->nb_philo));
	finish_meal(god, 0);
	free_god_almighty(god, god->nb_philo);
	return (1);
}
