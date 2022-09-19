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
/*
#include <stdio.h>
#include <pthread.h>

# define NC		"\e[0m"
# define YELLOW	"\e[1;33m"

void	*thread_routine(void *data)
{
	pthread_t	t_id;

	(void)data;
	t_id = pthread_self();
//	pthread_self() is forbidden in philo project but used here to know the
//	thread's ID
	printf("%sThread [%ld] : Hello World !%s\n", YELLOW, t_id, NC);
	return (NULL);
}

int	main(void)
{
	pthread_t	t_id_1;
	pthread_t	t_id_2;

	pthread_create(&t_id_1, NULL, thread_routine, NULL);
	printf("1st thread created [%ld]\n", t_id_1);
	pthread_create(&t_id_2, NULL, thread_routine, NULL);
	printf("2nd thread created [%ld]\n", t_id_2);
	pthread_join(t_id_1, NULL);
	printf("Joining 1st thread [%ld]\n", t_id_1);
	pthread_join(t_id_2, NULL);
	printf("Joining 2nd thread [%ld]\n", t_id_2);
	return (0);
}
*/

#include <stdio.h>
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
}