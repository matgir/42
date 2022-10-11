/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_philo1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:09:07 by mgirardo          #+#    #+#             */
/*   Updated: 2022/10/11 16:28:02 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libphilo.h"
#include <unistd.h>

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

void	*solo_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->god->forks[philo->fork[0]]);
	print_state(philo, " has taken a fork\n");
	quiet_time(philo->god, philo->god->die_ms);
	print_state(philo, " died\n");
	pthread_mutex_unlock(&philo->god->forks[philo->fork[0]]);
	return (NULL);
}

void	*eat_n_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->god->forks[philo->fork[0]]);
	if (meals_over(philo->god))
	{
		pthread_mutex_unlock(&philo->god->forks[philo->fork[0]]);
		return (NULL);
	}
	print_state(philo, " has taken a fork\n");
	pthread_mutex_lock(&philo->god->forks[philo->fork[1]]);
	if (meals_over(philo->god))
	{
		pthread_mutex_unlock(&philo->god->forks[philo->fork[1]]);
		pthread_mutex_unlock(&philo->god->forks[philo->fork[0]]);
		return (NULL);
	}
	print_state(philo, " has taken a fork\n");
	print_state(philo, " is eating\n");
	last_ate_update(philo);
	quiet_time(philo->god, philo->god->eat_ms);
	pthread_mutex_unlock(&philo->god->forks[philo->fork[1]]);
	pthread_mutex_unlock(&philo->god->forks[philo->fork[0]]);
	nb_ate_update(philo);
	return (NULL);
}

void	think(t_philo *philo)
{
	time_t	think_ms;

	pthread_mutex_lock(&philo->last_ate_mutex);
	think_ms = ((philo->god->die_ms - (get_time_in_ms()
					- philo->last_ate) - philo->god->eat_ms) / 3);
	pthread_mutex_unlock(&philo->last_ate_mutex);
	if (think_ms < 0)
		think_ms = 0;
	if (think_ms > 600)
		think_ms = 200;
	if (!meals_over(philo->god))
	{
		print_state(philo, " is thinking\n");
		quiet_time(philo->god, think_ms);
	}
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
	while (!meals_over(philo->god))
	{
		 usleep(200);//
		eat_n_sleep(philo);
		if (meals_over(philo->god))
			break ;
		print_state(philo, " is sleeping\n");
		quiet_time(philo->god, philo->god->sleep_ms);
		think(philo);
	}
	return (NULL);
}
