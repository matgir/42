#include "libphilo.h"
#include <unistd.h>

// #include <stdio.h>

int	dead_philo(t_philo *philo)
{
	time_t	time_to_die;

	time_to_die = get_time_in_ms();
	// pthread_mutex_lock(&philo->last_ate_mutex);
	if (time_to_die - philo->last_ate >= philo->god->die_ms)
	{
		pthread_mutex_lock(&philo->god->stop_mutex);
		philo->god->stop = 'Y';

		// printf("state of philo->god->stop = %c\n", philo->god->stop);

		pthread_mutex_unlock(&philo->god->stop_mutex);
		print_state(philo, " died\n");
		// pthread_mutex_unlock(&philo->last_ate_mutex);
		return (1);
	}
	// pthread_mutex_unlock(&philo->last_ate_mutex);
	return (0);
}

int	good_to_stop(t_omniscient *god)
{
	unsigned int	i;
	unsigned int	eat_enough;

	eat_enough = 0;
	i = 0;
	while (i < god->nb_philo)
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
				eat_enough = 1;
			pthread_mutex_unlock(&god->philos[i]->nb_ate_mutex);
		}
		pthread_mutex_unlock(&god->philos[i]->last_ate_mutex);
		i++;
	}
	if (god->nb_to_eat != -1 && eat_enough == 0)
	{
		pthread_mutex_lock(&god->stop_mutex);
		god->stop = 'Y';
		pthread_mutex_unlock(&god->stop_mutex);
		return (0);
	}
	return (1);
}

void	*omniscient(void *data)
{
	t_omniscient	*god;

	god = (t_omniscient *)data;
	if (god->nb_to_eat == 0)
		return (NULL);
	while (1)
	{
		if (!good_to_stop(god))
			return (NULL);
		usleep(500);
	}
	return (NULL);
}

