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

void	*take_fork_0(void *philoso)
{
	t_philo	*philo;

	philo = (t_philo *)philoso;
	if (philo->number == 0)
		pthread_mutex_lock(&philo->forks[philo->nb_philo]);
	else
		pthread_mutex_lock(&philo->forks[philo->number - 1]);
	printf("%ld %i has taken a fork\n", get_time_in_ms(), philo->number);
	pthread_mutex_lock(&philo->hf.h_forks_mutex);
	philo->hf.holding_forks++;
	pthread_mutex_unlock(&philo->hf.h_forks_mutex);
	while (1)
	{
		pthread_mutex_lock(&philo->hf.h_forks_mutex);
		if (philo->hf.holding_forks == 0)
			{
				pthread_mutex_unlock(&philo->hf.h_forks_mutex);
				if (philo->number == 0)
					pthread_mutex_unlock(&philo->forks[philo->nb_philo]);
				else
					pthread_mutex_unlock(&philo->forks[philo->number - 1]);
				break;
			}
		pthread_mutex_unlock(&philo->hf.h_forks_mutex);
	}
	return (NULL);
}

void	*take_fork_1(void *philoso)
{
	t_philo	*philo;

	philo = (t_philo *)philoso;
	pthread_mutex_lock(&philo->forks[philo->number]);
	printf("%ld %i has taken a fork\n", get_time_in_ms(), philo->number);
	pthread_mutex_lock(&philo->hf.h_forks_mutex);
	philo->hf.holding_forks++;
	pthread_mutex_unlock(&philo->hf.h_forks_mutex);
	while (1)
	{
		pthread_mutex_lock(&philo->hf.h_forks_mutex);
		if (philo->hf.holding_forks == 0)
			{
				pthread_mutex_unlock(&philo->hf.h_forks_mutex);
				pthread_mutex_unlock(&philo->forks[philo->number]);
				break;
			}
		pthread_mutex_unlock(&philo->hf.h_forks_mutex);
	}
/* 	while (philo->holding_forks != 2)
		usleep(1); */
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
/* 		if (philo->number == 0)
			pthread_mutex_lock(&philo->forks[philo->nb_philo]);
		else
			pthread_mutex_lock(&philo->forks[philo->number - 1]);
		printf("%ld %i has taken a fork\n", get_time_in_ms(), philo->number); */
		pthread_create(&philo->tid_fork_0, NULL, take_fork_0, philo);
		if (get_time_in_ms() > now_dead)
			break;
/* 		pthread_mutex_lock(&philo->forks[philo->number]);
		printf("%ld %i has taken a fork\n", get_time_in_ms(), philo->number); */
		pthread_create(&philo->tid_fork_1, NULL, take_fork_1, philo);
		if (get_time_in_ms() > now_dead)
			break;
		while (1)
		{
			pthread_mutex_lock(&philo->hf.h_forks_mutex);
			if (philo->hf.holding_forks == 2)
				{
					pthread_mutex_unlock(&philo->hf.h_forks_mutex);
					now_dead = get_time_in_ms() + philo->die_ms;
					printf("%ld %i is eating\n", get_time_in_ms(), philo->number);
					usleep(philo->eat_ms);
					break;
				}
			pthread_mutex_unlock(&philo->hf.h_forks_mutex);
		}
/* 		while (philo->hf.holding_forks != 2)
			usleep(1); */
		if (get_time_in_ms() > now_dead)
			break;
/* 		if (philo->number == 0)
			pthread_mutex_unlock(&philo->forks[philo->nb_philo]);
		else
			pthread_mutex_unlock(&philo->forks[philo->number - 1]); */
		pthread_mutex_lock(&philo->hf.h_forks_mutex);
		philo->hf.holding_forks = 0;
		pthread_mutex_unlock(&philo->hf.h_forks_mutex);
		if (get_time_in_ms() > now_dead)
			break;
		// pthread_mutex_unlock(&philo->forks[philo->number]);
		if (get_time_in_ms() > now_dead)
			break;
		printf("%ld %i is sleeping\n", get_time_in_ms(), philo->number);
		if (get_time_in_ms() > now_dead)
			break;
		usleep(philo->sleep_ms);
		if (get_time_in_ms() > now_dead)
			break;
		printf("%ld %i is thinking\n", get_time_in_ms(), philo->number);
	}
	philo->dead = 1;
// choper fork 0 puis 1
	// mager pendant tel temps
	// poser fork
	// dormir pendant tel temps
	// maybe think
	// repeat
	return (NULL);
}

void	*philo_routine_odd(void *philoso)
{
	t_philo	*philo;
	time_t	now_dead;

	usleep(100);
	philo = (t_philo *)philoso;
	now_dead = get_time_in_ms() + philo->die_ms;
	while (get_time_in_ms() < now_dead)
	{
/* 		pthread_mutex_lock(&philo->forks[philo->number]);
		printf("%ld %i has taken a fork\n", get_time_in_ms(), philo->number); */
		pthread_create(&philo->tid_fork_1, NULL, take_fork_1, philo);
		if (get_time_in_ms() > now_dead)
			break;
/* 		pthread_mutex_lock(&philo->forks[philo->number - 1]);
		printf("%ld %i has taken a fork\n", get_time_in_ms(), philo->number); */
		pthread_create(&philo->tid_fork_0, NULL, take_fork_0, philo);
		if (get_time_in_ms() > now_dead)
			break;
		while (1)
		{
			pthread_mutex_lock(&philo->hf.h_forks_mutex);
			if (philo->hf.holding_forks == 2)
				{
					pthread_mutex_unlock(&philo->hf.h_forks_mutex);
					now_dead = get_time_in_ms() + philo->die_ms;
					printf("%ld %i is eating\n", get_time_in_ms(), philo->number);
					usleep(philo->eat_ms);
					break;
				}
			pthread_mutex_unlock(&philo->hf.h_forks_mutex);
		}
/* 		while (philo->hf.holding_forks != 2)
			usleep(1); */
		if (get_time_in_ms() > now_dead)
			break;
		// pthread_mutex_unlock(&philo->forks[philo->number]);
		pthread_mutex_lock(&philo->hf.h_forks_mutex);
		philo->hf.holding_forks = 0;
		pthread_mutex_unlock(&philo->hf.h_forks_mutex);
		if (get_time_in_ms() > now_dead)
			break;
		// pthread_mutex_unlock(&philo->forks[philo->number - 1]);
		if (get_time_in_ms() > now_dead)
			break;
		printf("%ld %i is sleeping\n", get_time_in_ms(), philo->number);
		if (get_time_in_ms() > now_dead)
			break;
		usleep(philo->sleep_ms);
		if (get_time_in_ms() > now_dead)
			break;
		printf("%ld %i is thinking\n", get_time_in_ms(), philo->number);
	}
	philo->dead = 1;
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
	pthread_mutex_t	*forks;
	int i;
	int j;

	if (ac < 4)
		return (printf("ERROR"));
	i = ft_atoi(av[1]);
	// printf("beginning malloc, i = %i\n", i);
	forks = malloc(sizeof(pthread_mutex_t) * i + 1);
	philo = malloc(sizeof(t_philo) * i + 1);

	j = -1;
	while (++j < i)
	{
		// printf("beginning mutexes, j = %i\n", j);
		pthread_mutex_init(&forks[j], NULL);
	}
	j = -1;
	while (++j < i)
	{
		philo[j].nb_of_time_eaten = 0;
		philo[j].die_ms = ft_atoi(av[2]) * 1000;
		philo[j].eat_ms = ft_atoi(av[3]) * 1000;
		philo[j].sleep_ms = ft_atoi(av[4]) * 1000;
		philo[j].number = j;
		philo[j].forks = forks;
		philo[j].nb_philo = i - 1;
		philo[j].dead = 0;
		pthread_mutex_init(&philo[j].hf.h_forks_mutex, NULL);
		// pthread_mutex_init(&philo[j].fork_0, NULL);
	}




/* 	j = -1;
	while (++j < i - 1)
		philo[j].fork_1 = philo[j + 1].fork_0;
	philo[j].fork_1 = philo[0]. fork_0; */

	j = -1;
	while (++j < i)
	{
		// printf("beginning thread, j = %i\n", j);
		if ((j % 2) != 0)
			pthread_create(&philo[j].tid, NULL, philo_routine_odd, &philo[j]);
		else
			pthread_create(&philo[j].tid, NULL, philo_routine_even, &philo[j]);
	}
/* 	j = -1;
	while (++j < i) */
	j = -1;
	while (++j < i)
	{
		pthread_join(philo[j].tid, NULL);
		pthread_mutex_destroy(&forks[j]);
		pthread_mutex_destroy(&philo[j].hf.h_forks_mutex);
	}
	// printf("Value of j = %i", j);
	return (0);
}
