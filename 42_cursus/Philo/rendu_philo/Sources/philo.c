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

typedef struct s_omni
{
	pthread_mutex_t	is_dead_mutex;
	unsigned int	is_dead;
	unsigned int	times_eaten;
}					t_omni;

typedef struct s_philo
{
	int	nb_of_time_eaten; /* maybe to compare with the required amount each
	they eat, or not because not always needeed to check, do it if needeed
	with the omniscent thread */
	int	dead; /* set to 0 at the beginning and to 1 if philo is dead */
	int	die_ms;
	int	eat_ms;
	int	sleep_ms;
	int	holding_forks;
	int	id;
}		t_philo;

int	main(int ac, char **av)
{

}