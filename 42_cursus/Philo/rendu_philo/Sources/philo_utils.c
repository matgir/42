/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:05:57 by mgirardo          #+#    #+#             */
/*   Updated: 2022/10/11 16:05:58 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libphilo.h"
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>

void	print_state(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->god->write_mutex);
	printf("%li %i%s",
		get_time_in_ms() - philo->god->beginning, philo->number + 1, str);
	pthread_mutex_unlock(&philo->god->write_mutex);
}

time_t	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	quiet_time(t_omniscient *god, time_t quiet_time)
{
	time_t	no_no_jose;

	no_no_jose = get_time_in_ms() + quiet_time;
	while (get_time_in_ms() < no_no_jose)
	{
		if (meals_over(god))
			break ;
		usleep(100);
	}
}

int	start_meal(t_omniscient *god, unsigned int i)
{
	god->beginning = get_time_in_ms();
	while (i < god->nb_philo)
	{
		if (pthread_create(&god->philos[i]->philo_id,
				NULL, life, god->philos[i]) != 0)
			return (free_god_almighty(god, god->nb_philo));
		i += 2;
	}
	i = 1;
	usleep(2000);
	while (i < god->nb_philo)
	{
		if (pthread_create(&god->philos[i]->philo_id,
				NULL, life, god->philos[i]) != 0)
			return (free_god_almighty(god, god->nb_philo));
		i += 2;
	}
	if (god->nb_philo > 1)
	{
		if (pthread_create(&god->god_id, NULL, omniscient, god) != 0)
			return (free_god_almighty(god, god->nb_philo));
	}
	return (1);
}

void	finish_meal(t_omniscient *god, unsigned int i)
{
	while (i < god->nb_philo)
	{
		pthread_join(god->philos[i]->philo_id, NULL);
		i++;
		usleep(200);//
	}
	if (god->nb_philo > 1)
		pthread_join(god->god_id, NULL);
}
