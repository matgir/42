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

void	server_action(int sig, siginfo_t *info, void *context)
{
	(void)context;
	//for sending back information
	pid_t	client_pid = info->si_pid;
}

int	main(void)
{
	struct sigaction	siga;

	ft_printf("Server PID : %i\n", getpid());
	siga.sa_sigaction = server_action;
	siga.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &siga, NULL);
	sigaction(SIGUSR2, &siga, NULL);

	//maybe find a way to stop the server if needed

}