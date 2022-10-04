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

/* Here int i = number forks_mutex already init that need to be destroyed,
int j = nb_philo malloced that need to be freed */
void	*free_god_n_fork(t_omniscient *god, pthread_mutex_t *fork, int j, int i)
{
	while (--i >= 0)
		pthread_mutex_destroy(&fork[i]);
	if (fork != NULL)
		free(fork);
	while (j >= 0)
	{
		if (god->philos[j] != NULL)
			free(god->philos[j]);
		pthread_mutex_destroy(&god->philos[j]->last_ate_mutex);
		pthread_mutex_destroy(&god->philos[j]->nb_ate_mutex);
		j--;
	}
	if (god->philos != NULL)
		free(god->philos);
	if (god != NULL)
		free(god);
	return (NULL);
}

/* Here int j = nb_philo/forks/mutex malloced that need to be freed/destroy */
int	free_almost_god(t_omniscient *god, int j)
{
	while (j >= 0)
	{
		if (god->philos[j] != NULL)
			free(god->philos[j]);
		pthread_mutex_destroy(&god->philos[j]->last_ate_mutex);
		pthread_mutex_destroy(&god->philos[j]->nb_ate_mutex);
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

/* Here int j = nb_philo/forks/mutex malloced that need to be freed/destroy */
int	free_god_almighty(t_omniscient *god, int j)
{
	while (j >= 0)
	{
		if (god->philos[j] != NULL)
			free(god->philos[j]);
		pthread_mutex_destroy(&god->philos[j]->last_ate_mutex);
		pthread_mutex_destroy(&god->philos[j]->nb_ate_mutex);
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
