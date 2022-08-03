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
/*
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

*/




#include "libminitalk.h"

t_read	g_read;

void	reset_char_read(void)
{
	g_read.char_read[0] = -1;
	g_read.char_read[1] = -1;
	g_read.char_read[2] = -1;
	g_read.char_read[3] = -1;
	g_read.char_read[4] = -1;
	g_read.char_read[5] = -1;
	g_read.char_read[6] = -1;
	g_read.char_read[7] = -1;
}

char	get_char_from_byte(t_read read)
{
	char	character;
	int		binary;
	int		i;

	character = 0;
	i = 0;
	binary = 128;
	while (binary)
	{
		character += read.char_read[i] * binary;
		i++;
		binary >>= 1;
	}
	return (character);
}

void	make_read(int signum, int current, int pid)
{
	char	c;

	if (signum == SIGUSR1)
		g_read.char_read[current] = 0;
	if (signum == SIGUSR2)
		g_read.char_read[current] = 1;
	if (current == 7)
	{
		c = get_char_from_byte(g_read);
		if (c == '\0')
			ft_printf("\n\n     ===== Message received from %i =====     \n\n",
				pid);
		else
		{
			if (ft_printf("%c", c) == -1)
			{
				ft_printf("problem");
				if (kill(pid, SIGUSR1) == -1)
					ft_printf("problem");
			}
		}
		reset_char_read();
	}
}

void	signal_handler(int signum, siginfo_t *siginfo, void *ucontext)
{
	int		current;
	int		i;
	int		pid;

	(void) ucontext;
	pid = siginfo->si_pid;
	i = -1;
	while (++i < 8)
	{
		if (g_read.char_read[i] == -1)
		{
			current = i;
			break ;
		}
	}
	make_read(signum, current, pid);
	if (kill(pid, SIGUSR2) == -1)
		ft_printf("Unable to send confirmation to client\n");
}

int	main(void)
{
	int			pid;
	t_sigation	sa;

	ft_printf("Welcome to the Minitalk's server ! Starting ...\n");
	reset_char_read();
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGINT);
	sa.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = getpid();
	ft_printf("Server started ! You can send me a message with the PID %i !\n\n",
		pid);
	while (TRUE)
		;
}