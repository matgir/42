/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:32:30 by mgirardo          #+#    #+#             */
/*   Updated: 2022/09/19 14:32:34 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>

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

# define TIMES_TO_COUNT 21000

typedef struct s_counter
{
	pthread_mutex_t	count_mutex;
	unsigned int	count;
}					t_counter;

void	*thread_routine1(void *data)
{
	t_counter	*counter;
	unsigned int	i;

	counter = (t_counter *)data;
	pthread_mutex_lock(&counter->count_mutex);
	printf("%sThread [1] : Count start %u!%s\n", PURPLE, counter->count, NC);
	pthread_mutex_unlock(&counter->count_mutex);
	i = -1;
	while (++i < TIMES_TO_COUNT)
	{
		pthread_mutex_lock(&counter->count_mutex);
		counter->count++;
		pthread_mutex_unlock(&counter->count_mutex);
	}
	pthread_mutex_lock(&counter->count_mutex);
	printf("%sThread [1] : Final count %u!%s\n", PURPLE, counter->count, NC);
	pthread_mutex_unlock(&counter->count_mutex);
	return (NULL);
}

void	*thread_routine2(void *data)
{
	t_counter	*counter;
	unsigned int	i;

	counter = (t_counter *)data;
	pthread_mutex_lock(&counter->count_mutex);
	printf("%sThread [2] : Count start %u!%s\n", CYAN, counter->count, NC);
	pthread_mutex_unlock(&counter->count_mutex);
	i = -1;
	while (++i < TIMES_TO_COUNT)
	{
		pthread_mutex_lock(&counter->count_mutex);
		counter->count++;
		pthread_mutex_unlock(&counter->count_mutex);
	}
	pthread_mutex_lock(&counter->count_mutex);
	printf("%sThread [2] : Final count %u!%s\n", CYAN, counter->count, NC);
	pthread_mutex_unlock(&counter->count_mutex);
	return (NULL);
}
	
int	main(void)
{
	pthread_t		t_id_1;
	pthread_t		t_id_2;
	t_counter		counter;

	counter.count = 0;

	pthread_mutex_init(&counter.count_mutex, NULL);

	printf("Main : Expected count = %s%u%s\n", UGREEN, 2 * TIMES_TO_COUNT, NC);

	pthread_create(&t_id_1, NULL, thread_routine1, &counter);
	printf("Main : 1st thread created [%ld]\n", t_id_1);
	pthread_create(&t_id_2, NULL, thread_routine2, &counter);
	printf("Main : 2nd thread created [%ld]\n", t_id_2);

	pthread_join(t_id_1, NULL);
	printf("Main : Joining 1st thread [%ld]\n", t_id_1);
	pthread_join(t_id_2, NULL);
	printf("Main : Joining 2nd thread [%ld]\n", t_id_2);

	if (counter.count != (2 * TIMES_TO_COUNT))
		printf("%sMain : ERROR, total count = %u !%s", RED, counter.count, NC);
	else
		printf("%sMain : GOOD, total count = %u !%s\n", GREEN, counter.count, NC);
	pthread_mutex_destroy(&counter.count_mutex);
	return (0);
}
