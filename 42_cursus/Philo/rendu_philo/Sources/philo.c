/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:34:36 by mgirardo          #+#    #+#             */
/*   Updated: 2022/09/21 16:34:50 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include "libphilo.h"

// to make time to sleep, to eat, to die or to think
// 		usleep(time to ... * 1000) in order to have it in milliseconds

time_t	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	*philo_routine_odd(void *philoso)
{
	t_philo	*philo;
	time_t	now_dead;

	philo = (t_philo *)philoso;
	now_dead = get_time_in_ms() + philo->die_ms;
	while (get_time_in_ms() < now_dead)
	{
		pthread_mutex_lock(&philo->fork_0);
		printf("%ld %i has taken a fork\n", get_time_in_ms(), philo->number);
		pthread_mutex_lock(&philo->fork_1);
		printf("%ld %i has taken a fork\n", get_time_in_ms(), philo->number);
		now_dead = get_time_in_ms() + philo->die_ms;
		usleep(philo->eat_ms);
		printf("%ld %i is eating\n", get_time_in_ms(), philo->number);
		pthread_mutex_unlock(&philo->fork_0);
		pthread_mutex_unlock(&philo->fork_1);
		usleep(philo->sleep_ms);
		printf("%ld %i is sleeping\n", get_time_in_ms(), philo->number);
		printf("%ld %i is thinking\n", get_time_in_ms(), philo->number);
	}
	printf("%ld %i died\n", get_time_in_ms(), philo->number);
// choper fork 0 puis 1
	// mager pendant tel temps
	// poser fork
	// dormir pendant tel temps
	// maybe think
	// repeat
	return (NULL);
}

void	*philo_routine_even(void *philoso)
{
	t_philo	*philo;
	time_t	now_dead;

	philo = (t_philo *)philoso;
	now_dead = get_time_in_ms() + philo->die_ms;
	while (get_time_in_ms() < now_dead)
	{
		pthread_mutex_lock(&philo->fork_1);
		printf("%ld %i has taken a fork\n", get_time_in_ms(), philo->number);
		pthread_mutex_lock(&philo->fork_0);
		printf("%ld %i has taken a fork\n", get_time_in_ms(), philo->number);
		now_dead = get_time_in_ms() + philo->die_ms;
		usleep(philo->eat_ms);
		printf("%ld %i is eating\n", get_time_in_ms(), philo->number);
		pthread_mutex_unlock(&philo->fork_1);
		pthread_mutex_unlock(&philo->fork_0);
		usleep(philo->sleep_ms);
		printf("%ld %i is sleeping\n", get_time_in_ms(), philo->number);
		printf("%ld %i is thinking\n", get_time_in_ms(), philo->number);
	}
	printf("%ld %i died\n", get_time_in_ms(), philo->number);
// choper fork 1 puis 0
	// mager pendant tel temps
	// poser fork
	// dormir pendant tel temps
	// maybe think
	// repeat
	return (NULL);
}

int	main(int ac, char **av)
{
	// parsing avec message d'erreur pour les arguments pas bons
	// 		tcheck arg = unsigned int
	// 		si eat > die bloc
	// creer thread omniscient
	// creer les fork en structures de fork
	// faire tout les calculs necessaire au philos
	// creer les philo et rempir leurs infos
	// faire thread philo grace a boucles
	// join tout les threads

	t_philo			*philo;
	int i;
	int j;

	if (ac < 4)
		return (printf("ERROR"));
	i = ft_atoi(av[1]);
	philo = malloc(sizeof(philo) * i);

	j = -1;
	while (++j < i)
	{
		philo[j].nb_of_time_eaten = 0;
		philo[j].dead = 0;
		philo[j].die_ms = ft_atoi(av[2]) * 1000;
		philo[j].eat_ms = ft_atoi(av[3]) * 1000;
		philo[j].sleep_ms = ft_atoi(av[4]) * 1000;
		// philo[j].holding_forks = 0;
		philo[j].number = j;
		pthread_mutex_init(&philo[j].fork_0, NULL);
	}

	j = -1;
	while (++j < i - 1)
		philo[j].fork_1 = philo[j + 1].fork_0;
	philo[j].fork_1 = philo[0]. fork_0;

	j = -1;
	while (++j < i)
	{
		if ((j % 2) != 0)
			pthread_create(&philo[j].tid, NULL, philo_routine_odd, &philo[j]);
		else
			pthread_create(&philo[j].tid, NULL, philo_routine_even, &philo[j]);
	}
	while (++j < i)
		pthread_join(philo[j].tid, NULL);
	// printf("Value of j = %i", j);
	return (0);
}
