/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_philo2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 16:28:06 by mgirardo          #+#    #+#             */
/*   Updated: 2022/10/11 16:28:09 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libphilo.h"

void	nb_ate_update(t_philo *philo)
{
	if (!meals_over(philo->god))
	{
		pthread_mutex_lock(&philo->nb_ate_mutex);
		philo->nb_ate++;
		pthread_mutex_unlock(&philo->nb_ate_mutex);
	}
}

void	last_ate_update(t_philo *philo)
{
	pthread_mutex_lock(&philo->last_ate_mutex);
	philo->last_ate = get_time_in_ms();
	pthread_mutex_unlock(&philo->last_ate_mutex);
}
