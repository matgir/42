/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_free2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:35:26 by mgirardo          #+#    #+#             */
/*   Updated: 2022/10/03 16:57:07 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libphilo.h"
#include <stdlib.h>

int	free_almost_god(t_omniscient *god, int j)
{
	while (j >= 0)
	{
		if (god->philos[j] != NULL)
			free(god->philos[j]);
		pthread_mutex_destroy(&god->philos[j]->last_ate_mutex);
		pthread_mutex_destroy(&god->forks[j]);
		j--;
	}
	if (god->forks != NULL)
		free(god->forks);
	if (god->philos != NULL)
		free(god->philos);
	if (god != NULL)
		free(god);
	return (0);
}

void	*free_god_almighty(t_omniscient *god, int j)
{
	while (j >= 0)
	{
		if (god->philos[j] != NULL)
			free(god->philos[j]);
		pthread_mutex_destroy(&god->philos[j]->last_ate_mutex);
		pthread_mutex_destroy(&god->forks[j]);
		j--;
	}
	pthread_mutex_destroy(&god->stop_mutex);
	if (god->forks != NULL)
		free(god->forks);
	if (god->philos != NULL)
		free(god->philos);
	if (god != NULL)
		free(god);
	return (0);
}
