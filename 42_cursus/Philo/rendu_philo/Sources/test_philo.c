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
# define GREEN		"\e[32m"

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
	printf("%sThread [1] : Count start %u!%s\n", YELLOW, counter->count, NC);
	pthread_mutex_unlock(&counter->count_mutex);
	i = -1;
	while (++i < TIMES_TO_COUNT)
	{
		pthread_mutex_lock(&counter->count_mutex);
		counter->count++;
		pthread_mutex_unlock(&counter->count_mutex);
	}
	pthread_mutex_lock(&counter->count_mutex);
	printf("%sThread [1] : Final count %u!%s\n", YELLOW, counter->count, NC);
	pthread_mutex_unlock(&counter->count_mutex);
	return (NULL);
}

void	*thread_routine2(void *data)
{
	t_counter	*counter;
	unsigned int	i;

	counter = (t_counter *)data;
	pthread_mutex_lock(&counter->count_mutex);
	printf("%sThread [2] : Count start %u!%s\n", YELLOW, counter->count, NC);
	pthread_mutex_unlock(&counter->count_mutex);
	i = -1;
	while (++i < TIMES_TO_COUNT)
	{
		pthread_mutex_lock(&counter->count_mutex);
		counter->count++;
		pthread_mutex_unlock(&counter->count_mutex);
	}
	pthread_mutex_lock(&counter->count_mutex);
	printf("%sThread [2] : Final count %u!%s\n", YELLOW, counter->count, NC);
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

	printf("Main : Expected count = %s%u%s\n", GREEN, 2 * TIMES_TO_COUNT, NC);

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


/* #include <stdio.h>
#include <pthread.h>

# define NC	"\e[0m"
# define YELLOW	"\e[1;33m"

// thread_routine is the function the thread invokes right after its
// creation. The thread ends at the end of this function.
void	*thread_routine(void *data)
{
	pthread_t tid;
	(void)data;

	// Note that the pthread_self() function
	// is NOT allowed in the philosophers project !
	// We are only using it here as an example
	// to display this thread's ID.
	tid = pthread_self();
	printf("%sThread [%ld]: The heaviest burden is to exist without living.%s\n",
		YELLOW, tid, NC);
	return (NULL); // The thread ends here.
}

int	main(void)
{
	pthread_t	tid1;	// First thread's ID
	pthread_t	tid2;	// Second thread's ID

	// Creating the first thread that will go
	// execute its thread_routine function.
	pthread_create(&tid1, NULL, thread_routine, NULL);
	printf("Main: Created first thread [%ld]\n", tid1);
	// Creating the second thread that will also execute thread_routine.
	pthread_create(&tid2, NULL, thread_routine, NULL);
	printf("Main: Created second thread [%ld]\n", tid2);
	// The main thread waits for the new threads to end
	// with pthread_join.
	pthread_join(tid1, NULL);
	printf("Main: Joining first thread [%ld]\n", tid1);
	pthread_join(tid2, NULL);
	printf("Main: Joining second thread [%ld]\n", tid2);
	return (0);
} */