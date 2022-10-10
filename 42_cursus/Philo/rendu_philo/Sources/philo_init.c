/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:37:41 by mgirardo          #+#    #+#             */
/*   Updated: 2022/10/03 16:57:19 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libphilo.h"
#include <stdlib.h>

void	assign_forks(t_philo *philo)
{
	philo->fork[0] = philo->number;
	philo->fork[1] = (philo->number + 1) % philo->god->nb_philo;
	if (philo->number % 2)
	{
		philo->fork[0] = (philo->number + 1) % philo->god->nb_philo;
		philo->fork[1] = philo->number;
	}
}

t_philo	**init_philos(t_omniscient *god, unsigned int i)
{
	t_philo	**philos;

	philos = malloc(sizeof(t_philo) * god->nb_philo);
	if (philos == NULL)
		return (free_god(god));
	while (i < god->nb_philo)
	{
		philos[i] = malloc(sizeof(t_philo) * 1);
		if (!philos[i])
			return (free_god_n_philos(god, philos, i));
		philos[i]->god = god;
		philos[i]->number = i;
		philos[i]->nb_ate = 0;
		assign_forks(philos[i]);
		if (pthread_mutex_init(&philos[i]->last_ate_mutex, NULL) != 0)
			return (free_god_n_philos_n_mutex(god, philos, i));
		if (pthread_mutex_init(&philos[i]->nb_ate_mutex, NULL) != 0)
			return (free_god_n_philos_n_mutexes(god, philos, i));
		i++;
	}
	return (philos);
}

pthread_mutex_t	*init_forks(t_omniscient *god, unsigned int i)
{
	pthread_mutex_t	*forks;

	forks = malloc(sizeof(pthread_mutex_t) * god->nb_philo);
	if (!forks)
		return (free_god_wh_forks(god, god->nb_philo));
	while (i < god->nb_philo)
	{
		if (pthread_mutex_init(&forks[i], NULL) != 0)
			return (free_god_n_fork(god, forks, god->nb_philo, i));
		i++;
	}
	return (forks);
}

int	init_mutex(t_omniscient *god)
{
	god->forks = init_forks(god, 0);
	if (!god->forks)
		return (0);
	if (pthread_mutex_init(&god->stop_mutex, NULL) != 0)
		return (free_almost_god(god, god->nb_philo));
	// if (pthread_mutex_init(&god->write_mutex, NULL) != 0)
		// return (free_almost_god_n_mutex(god, god->nb_philo));
	return (1);
}

t_omniscient	*init(int argc, char **argv, int i)
{
	t_omniscient	*god;

	god = malloc(sizeof(t_omniscient) * 2);
	if (!god)
		return (NULL);
	god->nb_philo = atoi_philo(argv[i++]);
	god->die_ms = atoi_philo(argv[i++]);
	god->eat_ms = atoi_philo(argv[i++]);
	god->sleep_ms = atoi_philo(argv[i++]);
	god->nb_to_eat = -1;
	if (argc == 6)
		god->nb_to_eat = atoi_philo(argv[i++]);
	god->stop = 'N';
	god->philos = init_philos(god, 0);
	if (!god->philos)
		return (NULL);
	if (!init_mutex(god))
		return (NULL);
	return (god);
}
