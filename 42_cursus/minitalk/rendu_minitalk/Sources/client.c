/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:33:46 by mgirardo          #+#    #+#             */
/*   Updated: 2022/07/19 12:33:50 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libminitalk.h"

/*int	main(int ac, char **av)
{
	if (ac != 3 // || kill(ft_atoi(av[1]), 0) == 0 NEED TO UNDERSTAND BETTER KILL)
		return (-1);
	return (0);
}*/

static void	action(int sig)
{
	static int	received = 0;

	if (sig == SIGUSR1)
		++received;
	else
	{
		ft_printf("%i\n", received);
		exit(0);
	}
}

static void	mt_kill(int pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	if (ac != 3 || !ft_strlen(av[2]))
		return (1);
	ft_printf("Sent : %i\nReceived : ", ft_strlen(av[2]));
	signal(SIGUSR1, action);
	signal(SIGUSR2, action);
	mt_kill(ft_atoi(av[1]), av[2]);
	while (1)
		pause();
	return (0);
}