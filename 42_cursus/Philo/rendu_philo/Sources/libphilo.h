/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libphilo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:04:25 by mgirardo          #+#    #+#             */
/*   Updated: 2022/10/03 16:56:29 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPHILO_H
# define LIBPHILO_H

/* ########## INCLUDE ########## */

# include <pthread.h>

/* ########## STRUCT ########## */

typedef struct s_philo	t_philo;

typedef struct s_omniscient
{
	unsigned int	nb_philo;
	pthread_t		god_id;
	time_t			die_ms;
	time_t			eat_ms;
	time_t			sleep_ms;
	int				nb_to_eat;
	pthread_mutex_t	stop_mutex;
	char			stop;
	pthread_mutex_t	*forks;
	t_philo			**philos;
	time_t			beginning;
	// pthread_mutex_t	write_mutex;
}					t_omniscient;

typedef struct s_philo
{
	pthread_t		philo_id;
	unsigned int	number;
	pthread_mutex_t	nb_ate_mutex;
	unsigned int	nb_ate;
	unsigned int	fork[2];
	pthread_mutex_t	last_ate_mutex;
	time_t			last_ate;
	t_omniscient	*god;

}					t_philo;

/* ########## FUNCTIONS ########## */

/***** INIT *****/
t_philo			**init_philos(t_omniscient *god, unsigned int i);
pthread_mutex_t	*init_forks(t_omniscient *god, unsigned int i);
int				init_mutex(t_omniscient *god);
t_omniscient	*init(int argc, char **argv, int i);
void			assign_forks(t_philo *philo);

/***** PHILO *****/
void			*life(void *data);
void			*solo_philo(t_philo *philo);
void			*eat_n_sleep(t_philo *philo);
void			think(t_philo *philo);
int				meals_over(t_omniscient *god);
void			last_ate_update(t_philo *philo);
void			nb_ate_update(t_philo *philo);

/***** FREE *****/
void			*free_god(t_omniscient *god);
void			*free_god_n_philos(t_omniscient *god, t_philo **philos, int i);
void			*free_god_n_philos_n_mutex(
					t_omniscient *god, t_philo **philos, int i);
void			*free_god_wh_forks(t_omniscient *god, int j);
void			*free_god_n_fork(
					t_omniscient *god, pthread_mutex_t *fork, int j, int i);
int				free_almost_god(t_omniscient *god, int j);
int				free_almost_god_n_mutex(t_omniscient *god, int j);
void			*free_god_n_philos_n_mutexes(
					t_omniscient *god, t_philo **philos, int i);
int				free_god_almighty(t_omniscient *god, int j);

/***** GOD *****/
void			*omniscient(void *data);
int				dead_philo(t_philo *philo);
int				good_to_stop(t_omniscient *god);
void			setting_state(t_omniscient *god);
int				status_check(
					t_omniscient *god, int i, unsigned int *eat_enough);

/***** PARSING *****/
int				parsing_philo(int argc, char **argv);
size_t			ft_strlen(char *str);
int				atoi_philo(char	*str);
int				digit_check(char *str);
int				ft_isdigit(int c);

/***** UTILS *****/
void			quiet_time(t_omniscient *god, time_t quiet_time);
time_t			get_time_in_ms(void);
void			print_state(t_philo *philo, char *str);
int				start_meal(t_omniscient *god, unsigned int i);
void			finish_meal(t_omniscient *god, unsigned int i);

#endif
