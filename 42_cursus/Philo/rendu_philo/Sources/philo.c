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

#include "libphilo.h"
#include <stdio.h>
#include <sys/time.h>

time_t	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec * 1000));
}

void	print_state(t_philo *philo, char *str)
{
	printf("%li %i%s", get_time_in_ms() - philo->god->beginning, philo->number + 1, str);
}

int	meals_over(t_omniscient *god)
{
	pthread_mutex_lock(&god->stop_mutex);
	if (god->stop == 'N')
	{
		pthread_mutex_unlock(&god->stop_mutex);
		return (0);
	}
	else
	{
		pthread_mutex_unlock(&god->stop_mutex);
		return (1);
	}
}

void	temps_calme(t_omniscient *god, time_t time)
{
	time_t	no_no_jose;

	no_no_jose = get_time_in_ms() + time;
	while (get_time_in_ms() < no_no_jose)
	{
		if (meals_over(god))
			break;
		usleep(100);
	}
}

void	*solo_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->god->forks[philo->fork[0]]);
	print_state(philo, " has taken a fork\n");
	temps_calme(philo->god, philo->god->die_ms);
	print_state(philo, " died\n");
	pthread_mutex_unlock(&philo->god->forks[philo->fork[0]]);
	return (NULL);
}

void	eat_n_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->god->forks[philo->fork[0]]);
	print_state(philo, " has taken a fork\n");
	pthread_mutex_lock(&philo->god->forks[philo->fork[1]]);
	print_state(philo, " has taken a fork\n");
	print_state(philo, " is eating\n");
	pthread_mutex_lock(&philo->last_ate_mutex);
	philo->last_ate = get_time_in_ms();
	pthread_mutex_unlock(&philo->last_ate_mutex);
	temps_calme(philo->god, philo->god->eat_ms);
	if (!meal_over(philo->god))
	{
		pthread_mutex_lock(&philo->nb_ate_mutex);
		philo->nb_ate++;
		pthread_mutex_unlock(&philo->nb_ate_mutex);
	}
	print_state(philo, " is sleeping\n");
	pthread_mutex_unlock(&philo->god->forks[philo->fork[1]]);
	pthread_mutex_unlock(&philo->god->forks[philo->fork[0]]);
	temps_calme(philo->god, philo->god->sleep_ms);
}

void	think(t_philo *philo)
{
	time_t	think_ms;

	pthread_mutex_lock(&philo->last_ate_mutex);
	think_ms = (philo->god->die_ms - (get_time_in_ms() - philo->last_ate) - philo->god->eat_ms) / 2;
	pthread_mutex_unlock(&philo->last_ate_mutex);
	if (think_ms < 0)
		think_ms = 0;
	if (think_ms > 600)
		think_ms = 200;
	print_state(philo, " is thinking\n");
	temps_calme(philo->god, think_ms);
}

void	*life(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->god->nb_to_eat == 0)
		return (NULL);
	pthread_mutex_lock(&philo->last_ate_mutex);
	philo->last_ate = get_time_in_ms();
	pthread_mutex_unlock(&philo->last_ate_mutex);
	if (philo->god->die_ms == 0)
		return (NULL);
	if (philo->god->nb_philo == 1)
		return (solo_philo(philo));
	while (meals_over(philo->god))
	{
		eat_n_sleep(philo);
		think(philo);
	}
	return (NULL);
}

void	*omniscient(void *data)
{
	t_omniscient	*god;

	god = (t_omniscient *)data;
}

int	start_meal(t_omniscient *god, unsigned int i)
{
	god->beginning = get_time_in_ms();
	while (i < god->nb_philo)
	{
		if (pthread_create(&god->philos[i]->philo_id, NULL, life, &god->philos[i]) != 0)
			return (free_god_almighty(god, god->nb_philo));
	}
	i = 1;
	while (i < god->nb_philo)
	{
		if (pthread_create(&god->philos[i]->philo_id, NULL, life, &god->philos[i]) != 0)
			return (free_god_almighty(god, god->nb_philo));
	}
	if (god->nb_philo > 1)
	{
		if (pthread_create(&god->god_id, NULL, omniscient, &god) != 0)
			return (free_god_almighty(god, god->nb_philo));
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_omniscient	*god;

	god = NULL;
	if (!parsing_philo(argc, argv))
		return (printf("Wrong arguments\n"));
	god = init(argc, argv, 1);
	if (god == NULL)
		return (0);
/* 
	int i = -1;
	while (++i < atoi_philo(argv[1]))
		printf("philo number %i will hold forks number %i and %i\n",
			god->philos[i]->number, god->philos[i]->fork[0],
			god->philos[i]->fork[1]);
 */
	if (!start_meal(god, 0))
		return (free_god_almighty(god, god->nb_philo));
	return (1);
}
