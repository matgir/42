/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_god.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:49:10 by mgirardo          #+#    #+#             */
/*   Updated: 2022/10/11 15:49:14 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/libphilo.h"
#include <unistd.h>

void	setting_state(t_omniscient *god)
{
	pthread_mutex_lock(&god->stop_mutex);
	god->stop = 'Y';
	pthread_mutex_unlock(&god->stop_mutex);
}

int	dead_philo(t_philo *philo)
{
	time_t	time_to_die;

	time_to_die = get_time_in_ms();
	if (time_to_die - philo->last_ate >= philo->god->die_ms)
	{
		setting_state(philo->god);
		print_state(philo, " died\n");
		return (1);
	}
	return (0);
}

int	status_check(t_omniscient *god, int i, unsigned int *eat_enough)
{
	pthread_mutex_lock(&god->philos[i]->last_ate_mutex);
	if (dead_philo(god->philos[i]))
	{
		pthread_mutex_unlock(&god->philos[i]->last_ate_mutex);
		return (0);
	}
	if (god->nb_to_eat != -1)
	{
		pthread_mutex_lock(&god->philos[i]->nb_ate_mutex);
		if (god->philos[i]->nb_ate < (unsigned int)god->nb_to_eat)
			*eat_enough = 1;
		pthread_mutex_unlock(&god->philos[i]->nb_ate_mutex);
	}
	pthread_mutex_unlock(&god->philos[i]->last_ate_mutex);
	return (1);
}

int	good_to_stop(t_omniscient *god)
{
	unsigned int	i;
	unsigned int	eat_enough;

	eat_enough = 0;
	i = 0;
	while (i < god->nb_philo)
	{
		if (!status_check(god, (int)i, &eat_enough))
			return (0);
		i++;
	}
	if (god->nb_to_eat != -1 && eat_enough == 0)
	{
		setting_state(god);
		return (0);
	}
	return (1);
}

void	*omniscient(void *data)
{
	t_omniscient	*god;

	god = (t_omniscient *)data;
	usleep(2000);
	if (god->nb_to_eat == 0)
		return (NULL);
	while (1)
	{
		if (!good_to_stop(god))
			return (NULL);
		usleep(100);
	}
	return (NULL);
}
