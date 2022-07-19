/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 11:23:17 by mgirardo          #+#    #+#             */
/*   Updated: 2022/07/19 11:23:19 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libminitalk.h"
#include <signal.h>

/*int	main(void)
{
	ft_printf("Server PID : %i\n", getpid());
}*/

static void	action(int sig, siginfo_t *info, void *context)
{
	static int				i = 0;
	static __pid_t			client_pid = 0;
	static unsigned char	c = 0;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	c |= (sig == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			kill(client_pid, SIGUSR2);
			client_pid = 0;
			return ;
		}
		ft_putchar_fd(c, 1);
		c = 0;
		kill(client_pid, SIGUSR1);
	}
	else
		c <<= 1;
}

int	main(void)
{
	const struct sigaction	s_sigaction;

	ft_printf("Server PID : %i\n", getpid());
	s_sigaction.sa_sigaction = action;
	s_sigaction.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_sigaction, 0);
	sigaction(SIGUSR2, &s_sigaction, 0);
	while (1)
		pause();
	return(0);
}