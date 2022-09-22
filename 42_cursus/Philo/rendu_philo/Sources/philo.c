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

typedef struct s_omniscient
{
	pthread_mutex_t	is_dead_mutex;
	unsigned int	is_dead;
	unsigned int	times_eaten;
}					t_omniscient;

typedef struct s_philo
{
	int			nb_of_time_eaten; /* maybe to compare with the required amount each
	they eat, or not because not always needeed to check, do it if needeed
	with the omniscent thread */
	int			dead; /* set to 0 at the beginning and to 1 if philo is dead */
	int			die_ms;
	int			eat_ms;
	int			sleep_ms;
	int			holding_forks;
	pthread_t	tid;
	int			number;
}		t_philo;

// to make time to sleep, to eat, to die or to think
// 		usleep(time to ... * 1000) in order to have it in milliseconds

int	main(int ac, char **av)
{
	// parsing avec message d'erreur pour les arguments pas bons
	// 		tcheck arg = unsigned int
	// creer thread omniscient
	// creer les fork en structures de fork
	// faire tout les calculs necessaire au philos
	// creer les philo et rempir leurs infos
	// faire thread philo grace a boucles
	// join tout les threads
	t_philo	**philo;
	int i;

	i = ft_atoi(av[2]);
	philo = malloc(sizeof(*philo) * i);
	while (i-- >= 0)
	{
		philo[i]->nb_of_time_eaten = 0;
		philo[i]->dead = 0;
		philo[i]->die_ms = ft_atoi(av[3]) * 1000;
		philo[i]->eat_ms = ft_atoi(av[4]) * 1000;
		philo[i]->sleep_ms = ft_atoi(av[5]) * 1000;
		philo[i]->holding_forks = 0;
		philo[i]->tid = 
	}
}
