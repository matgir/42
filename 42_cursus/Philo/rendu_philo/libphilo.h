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

/* ########## STRUCT ########## */

typedef struct s_philo t_philo;

typedef struct s_omniscient
{
	unsigned int	nb_philo;
	pthread_t		god_id;
	time_t			die_ms;
	time_t			eat_ms;
	time_t			sleep_ms;
	int				nb_to_eat; /* en int car si pas d'infos alors = -1 */
	pthread_mutex_t	stop_mutex;
	char			stop; /* y if stop, n if continue */
	// pthread_mutex_t	god_mutex;
	pthread_mutex_t	*forks;
	t_philo			**philos;
}					t_omniscient;

typedef struct s_philo
{
	pthread_t	philo_id;
	unsigned int	number;
	unsigned int	nb_ate;
	unsigned int	fork[2]; /* put fork number lefty or righty occording to
								philo number*/
	pthread_mutex_t	last_ate_mutex;
	time_t			last_ate;
	t_omniscient	*god;

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