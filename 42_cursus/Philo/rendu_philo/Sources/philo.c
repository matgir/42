/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:34:36 by mgirardo          #+#    #+#             */
/*   Updated: 2022/09/28 15:02:47 by mgirardo         ###   ########.fr       */
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

int	has_simulation_stopped(t_omniscient *god)
{
	pthread_mutex_lock(&god->is_dead.is_dead_mutex);
	if (god->is_dead.is_dead == 1)
	{
		pthread_mutex_unlock(&god->is_dead.is_dead_mutex);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(&god->is_dead.is_dead_mutex);
		return (0);
	}
}

time_t	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_usleep(time_t break_time)
{
	time_t	break_finished;

	break_finished = get_time_in_ms() + (break_time / 1000);
	while (get_time_in_ms() < break_finished)
	{
		/* 		if (get_time_in_ms() > break_finished)
				break; */
		usleep(100);
		// printf("i'm in\n%li is still < %li", get_time_in_ms(), break_finished);
		/* 		if (get_time_in_ms() > break_finished)
				break; */
	}
	// printf("i'm out YOUHOU\n");
}

void	print_status(t_philo *philo, char *str)
{
	printf("%li %i %s", get_time_in_ms() - philo->god->start_time, philo->number, str);
}

void	*take_fork_0(void *philoso)
{
	t_philo	*philo;

	philo = (t_philo *)philoso;
	if (philo->number == 0)
		pthread_mutex_lock(&philo->forks[philo->nb_philo]);
	else
		pthread_mutex_lock(&philo->forks[philo->number - 1]);
	print_status(philo, "has taken a fork\n");
	// printf("%ld %i has taken a fork\n", get_time_in_ms(), philo->number);
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
	print_status(philo, "has taken a fork\n");
	// printf("%ld %i has taken a fork\n", get_time_in_ms(), philo->number);
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
	return (NULL);
}

void	*philo_routine_even(void *philoso)
{
	t_philo	*philo;
	// time_t	now_dead;

	// usleep(5000);
	philo = (t_philo *)philoso;
/* 	pthread_mutex_lock(&philo->time_eaten.time_eaten_mutex);
	philo->time_eaten.time_eaten = get_time_in_ms() - philo->god->start_time;
	pthread_mutex_unlock(&philo->time_eaten.time_eaten_mutex); */
	while (has_simulation_stopped(philo->god) != 0)
	{
		/* 		if (philo->number == 0)
				pthread_mutex_lock(&philo->forks[philo->nb_philo]);
				else
				pthread_mutex_lock(&philo->forks[philo->number - 1]);
				printf("%ld %i has taken a fork\n", get_time_in_ms(), philo->number); */
		pthread_create(&philo->tid_fork_0, NULL, take_fork_0, philo);
		if (has_simulation_stopped(philo->god) != 0)
			break;
		/* 		pthread_mutex_lock(&philo->forks[philo->number]);
				printf("%ld %i has taken a fork\n", get_time_in_ms(), philo->number); */
		pthread_create(&philo->tid_fork_1, NULL, take_fork_1, philo);
		if (has_simulation_stopped(philo->god) != 0)
			break;
		while (1)
		{
			pthread_mutex_lock(&philo->hf.h_forks_mutex);
			if (philo->hf.holding_forks == 2)
			{
				pthread_mutex_unlock(&philo->hf.h_forks_mutex);
				pthread_mutex_lock(&philo->time_eaten.time_eaten_mutex);
				philo->time_eaten.time_eaten = get_time_in_ms() - philo->god->start_time;
				pthread_mutex_unlock(&philo->time_eaten.time_eaten_mutex);
				print_status(philo, "is eating\n");
				// printf("%ld %i is eating\n", get_time_in_ms(), philo->number);
				ft_usleep(philo->eat_ms);
				// usleep(philo->eat_ms);
				pthread_mutex_lock(&philo->hf.h_forks_mutex);
				philo->hf.holding_forks = 0;
				pthread_mutex_unlock(&philo->hf.h_forks_mutex);
				break;
			}
			pthread_mutex_unlock(&philo->hf.h_forks_mutex);
		}
		/* 		while (philo->hf.holding_forks != 2)
				usleep(1); */
		/* 		if (get_time_in_ms() > now_dead)
				break; */
		/* 		if (philo->number == 0)
				pthread_mutex_unlock(&philo->forks[philo->nb_philo]);
				else
				pthread_mutex_unlock(&philo->forks[philo->number - 1]); */
		if (has_simulation_stopped(philo->god) != 0)
			break;
		// pthread_mutex_unlock(&philo->forks[philo->number]);
		print_status(philo, "is sleeping\n");
		// printf("%ld %i is sleeping\n", get_time_in_ms(), philo->number);
		if (has_simulation_stopped(philo->god) != 0)
			break;
		ft_usleep(philo->sleep_ms);
		// usleep(philo->sleep_ms);
		if (has_simulation_stopped(philo->god) != 0)
			break;
		print_status(philo, "is thinking\n");
		pthread_join(philo->tid_fork_1, NULL);
		pthread_join(philo->tid_fork_0, NULL);
		// printf("%ld %i is thinking\n", get_time_in_ms(), philo->number);
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
	// time_t	now_dead;

	philo = (t_philo *)philoso;
/* 	pthread_mutex_lock(&philo->time_eaten.time_eaten_mutex);
	philo->time_eaten.time_eaten = get_time_in_ms() - philo->god->start_time;
	pthread_mutex_unlock(&philo->time_eaten.time_eaten_mutex); */
	while (has_simulation_stopped(philo->god) == 0)
	{
		/* 		pthread_mutex_lock(&philo->forks[philo->number]);
				printf("%ld %i has taken a fork\n", get_time_in_ms(), philo->number); */
		pthread_create(&philo->tid_fork_1, NULL, take_fork_1, philo);
		if (has_simulation_stopped(philo->god) != 0)
			break;
		/* 		pthread_mutex_lock(&philo->forks[philo->number - 1]);
				printf("%ld %i has taken a fork\n", get_time_in_ms(), philo->number); */
		pthread_create(&philo->tid_fork_0, NULL, take_fork_0, philo);
		if (has_simulation_stopped(philo->god) != 0)
			break;
		while (1)
		{
			pthread_mutex_lock(&philo->hf.h_forks_mutex);
			if (philo->hf.holding_forks == 2)
			{
				pthread_mutex_unlock(&philo->hf.h_forks_mutex);
				pthread_mutex_lock(&philo->time_eaten.time_eaten_mutex);
				philo->time_eaten.time_eaten = get_time_in_ms() - philo->god->start_time;
				pthread_mutex_unlock(&philo->time_eaten.time_eaten_mutex);
				// now_dead = get_time_in_ms() + philo->die_ms;
				print_status(philo, "is eating\n");
				// printf("%ld %i is eating\n", get_time_in_ms(), philo->number);
				ft_usleep(philo->eat_ms);
				// usleep(philo->eat_ms);
				pthread_mutex_lock(&philo->hf.h_forks_mutex);
				philo->hf.holding_forks = 0;
				pthread_mutex_unlock(&philo->hf.h_forks_mutex);
				break;
			}
			pthread_mutex_unlock(&philo->hf.h_forks_mutex);
		}
		/* 		while (philo->hf.holding_forks != 2)
				usleep(1); */
		/* 		if (get_time_in_ms() > now_dead)
				break; */
		// pthread_mutex_unlock(&philo->forks[philo->number]);
		if (has_simulation_stopped(philo->god) != 0)
			break;
		// pthread_mutex_unlock(&philo->forks[philo->number - 1]);
		print_status(philo, "is sleeping\n");
		// printf("%ld %i is sleeping\n", get_time_in_ms(), philo->number);
		if (has_simulation_stopped(philo->god) != 0)
			break;
		ft_usleep(philo->sleep_ms);
		// usleep(philo->sleep_ms);
		if (has_simulation_stopped(philo->god) != 0)
			break;
		print_status(philo, "is thinking\n");
		pthread_join(philo->tid_fork_0, NULL);
		pthread_join(philo->tid_fork_1, NULL);
		// printf("%ld %i is thinking\n", get_time_in_ms(), philo->number);
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

void	*god_routine(void	*omniscient)
{
	/* 
	   - boucles qui verif etat philo dead or not
	   - if nb_to_eat boucles qui verif quqnd tout le monde a manger
	   */
	t_omniscient	*god;
	int				j;

	god = (t_omniscient *)omniscient;
	while (has_simulation_stopped(god) == 0)
	{
		j = -1;
		while (++j < god->nb_philo)
		{
			pthread_mutex_lock(&god->philos[j]->time_eaten.time_eaten_mutex);
			if (god->philos[j]->time_eaten.time_eaten == -1)
			{
				pthread_mutex_unlock(&god->philos[j]->time_eaten.time_eaten_mutex);
				break;
			}
			pthread_mutex_unlock(&god->philos[j]->time_eaten.time_eaten_mutex);
			pthread_mutex_lock(&god->philos[j]->time_eaten.time_eaten_mutex);
			if (get_time_in_ms() - god->philos[j]->time_eaten.time_eaten >= god->philos[j]->eat_ms/1000)
			{
				pthread_mutex_unlock(&god->philos[j]->time_eaten.time_eaten_mutex);
				pthread_mutex_lock(&god->is_dead.is_dead_mutex);
				god->is_dead.is_dead = 1;
				pthread_mutex_unlock(&god->is_dead.is_dead_mutex);
				break;
			}
			pthread_mutex_unlock(&god->philos[j]->time_eaten.time_eaten_mutex);
		}
	}
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
	t_omniscient	god;
	int i;
	int j;

	if (ac < 4)
		return (printf("ERROR"));
	i = ft_atoi(av[1]);
	// printf("beginning malloc, i = %i\n", i);
	forks = malloc(sizeof(pthread_mutex_t) * i + 1);
	philo = malloc(sizeof(t_philo) * i + 1);

	if (ac == 5)
	{
		god.nb_to_eat = -1;
		god.has_eaten = -1;
	}
	else if (ac == 6)
	{
		god.nb_to_eat = ft_atoi(av[5]);
		god.has_eaten = 0;
	}
	god.nb_philo = i;
	god.start_time = get_time_in_ms();
	pthread_mutex_init(&god.is_dead.is_dead_mutex, NULL);
	pthread_mutex_lock(&god.is_dead.is_dead_mutex);
	god.is_dead.is_dead = 0;
	pthread_mutex_unlock(&god.is_dead.is_dead_mutex);
	god.philos = &philo;


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
		philo[j].number = j + 1;
		philo[j].forks = forks;
		philo[j].nb_philo = i - 1;
		philo[j].dead = 0;
		philo[j].god = &god;
		pthread_mutex_init(&philo[j].hf.h_forks_mutex, NULL);
		pthread_mutex_lock(&philo[j].hf.h_forks_mutex);
		philo[j].hf.holding_forks = 0;
		pthread_mutex_unlock(&philo[j].hf.h_forks_mutex);
		pthread_mutex_init(&philo[j].time_eaten.time_eaten_mutex, NULL);
		pthread_mutex_lock(&philo[j].time_eaten.time_eaten_mutex);
		philo[j].time_eaten.time_eaten = -1;
		pthread_mutex_unlock(&philo[j].time_eaten.time_eaten_mutex);
		// pthread_mutex_init(&philo[j].fork_0, NULL);
	}

	/* 	j = -1;
		while (++j < i - 1)
		philo[j].fork_1 = philo[j + 1].fork_0;
		philo[j].fork_1 = philo[0]. fork_0; */

	pthread_create(&god.tid, NULL, god_routine, &god);

	j = -1;
	while (++j < i)
	{
		// printf("beginning thread, j = %i\n", j);
		if ((philo[j].number % 2) == 0)
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
		// pthread_mutex_unlock(&forks[j]);
	}
	j = -1;
	while (++j < i)
	{
		// pthread_join(philo[j].tid, NULL);
		pthread_mutex_destroy(&forks[j]);
		pthread_mutex_destroy(&philo[j].hf.h_forks_mutex);
	}
	pthread_mutex_destroy(&god.is_dead.is_dead_mutex);
	// printf("Value of j = %i", j);
	return (0);
}
