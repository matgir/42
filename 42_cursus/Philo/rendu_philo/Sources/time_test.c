/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 12:23:17 by mgirardo          #+#    #+#             */
/*   Updated: 2022/09/21 12:23:21 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

time_t	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	main(void)
{	
	time_t	start_time;
	time_t	end_time;
	time_t	time;

	start_time = get_time_in_ms();
	end_time = start_time + 2000;
	time = get_time_in_ms();
	printf("Time in ms = %ld. Time in ms since start = %ld\n",
		time, time - start_time);
	while (get_time_in_ms() < end_time)
	{
		usleep(100 * 1000);
		time = get_time_in_ms();
		printf("Time in ms = %ld. Time in ms since start = %ld\n",
			time, time - start_time);
	}
	return (0);
}
