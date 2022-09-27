/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libphilo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:04:25 by mgirardo          #+#    #+#             */
/*   Updated: 2022/09/21 13:04:30 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPHILO_H
# define LIBPHILO_H

# include <pthread.h>
# include "libphilo.h"

/* ########## STRUCT ########## */

typedef struct s_philo t_philo;


typedef struct s_is_dead
{
	pthread_mutex_t	is_dead_mutex;
	int				is_dead;
}					t_is_dead;

typedef struct s_omniscient
{
	t_is_dead		is_dead;
	unsigned int	nb_to_eat;
	time_t			start_time;
	int				nb_philo;
	int				has_eaten;
	pthread_t		tid;
	t_philo			**philos;
}					t_omniscient;

typedef struct s_holding_forks
{
	pthread_mutex_t	h_forks_mutex;
	int				holding_forks;
}					t_holding_forks;

typedef struct s_philo
{
	int				nb_of_time_eaten; /* maybe to compare with the required amount each
	they eat, or not because not always needeed to check, do it if needeed
	with the omniscent thread */
	int				dead;
	time_t			die_ms;
	time_t			eat_ms;
	time_t			sleep_ms;
	pthread_t		tid;
	int				number;
	pthread_mutex_t	*forks;
	int				nb_philo;
	// pthread_mutex_t	fork_0;
	pthread_t		tid_fork_0;
	// pthread_mutex_t	fork_1;
	pthread_t		tid_fork_1;
	t_holding_forks	hf; /* quand = 2 alors lancer le manger */
	t_omniscient	*god;
	int				last_time_eaten;
}					t_philo;

/* ########## USEFULL ########## */

# define NC			"\e[0m"
# define BYELLOW	"\e[1;33m"
# define YELLOW		"\e[33m"
# define RED		"\e[31m"
# define BLACK		"\e[30m"
# define BLUE		"\e[34m"
# define PURPLE		"\e[35m"
# define CYAN		"\e[36m"
# define ICYAN		"\e[0;96m"
# define GREEN		"\e[32m"
# define UGREEN		"\e[4;32m"

/* ########## FUNCTIONS ########## */

long int	ft_atoi(const char *nptr);

#endif