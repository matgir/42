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

#include <pthread.h>

/* ########## STRUCT ########## */

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

#endif