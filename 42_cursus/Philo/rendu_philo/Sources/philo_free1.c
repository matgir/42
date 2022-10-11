/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_free1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:35:18 by mgirardo          #+#    #+#             */
/*   Updated: 2022/10/03 16:57:00 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libphilo.h"
#include <stdlib.h>

void	*free_god(t_omniscient *god)
{
	if (god != NULL)
		free(god);
	return (NULL);
}

/* Here int i = number of philo already malloced that need to be freed */
void	*free_god_n_philos(t_omniscient *god, t_philo **philos, int i)
{
	while (--i >= 0)
	{
		if (philos[i] != NULL)
			free(philos[i]);
	}
	if (philos != NULL)
		free(philos);
	if (god != NULL)
		free(god);
	return (NULL);
}

/* Here int i = number of philo already malloced that need to be freed */
void	*free_god_n_philos_n_mutex(t_omniscient *god, t_philo **philos, int i)
{
	while (--i >= 0)
	{
		pthread_mutex_destroy(&philos[i]->last_ate_mutex);
		if (philos[i] != NULL)
			free(philos[i]);
	}
	if (philos != NULL)
		free(philos);
	if (god != NULL)
		free(god);
	return (NULL);
}

/* Here int i = number of philo already malloced that need to be freed */
void	*free_god_n_philos_n_mutexes(t_omniscient *god, t_philo **philos, int i)
{
	while (--i >= 0)
	{
		pthread_mutex_destroy(&philos[i]->last_ate_mutex);
		pthread_mutex_destroy(&philos[i]->nb_ate_mutex);
		if (philos[i] != NULL)
			free(philos[i]);
	}
	if (philos != NULL)
		free(philos);
	if (god != NULL)
		free(god);
	return (NULL);
}

/* Here int j = nb_philo malloced that need to be freed */
void	*free_god_wh_forks(t_omniscient *god, int j)
{
	while (--j >= 0)
	{
		pthread_mutex_destroy(&god->philos[j]->last_ate_mutex);
		pthread_mutex_destroy(&god->philos[j]->nb_ate_mutex);
		if (god->philos[j] != NULL)
			free(god->philos[j]);
	}
	if (god->philos != NULL)
		free(god->philos);
	if (god != NULL)
		free(god);
	return (NULL);
}
