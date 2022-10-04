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

void	*life(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
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
			retrun (free_god_almighty(god, god->nb_philo));
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
