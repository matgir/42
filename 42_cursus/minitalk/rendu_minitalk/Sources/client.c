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

t_to_send	g_infos;

void	parsing_minitalk(int ac, char **av)
{
	if (ac == -1 && av == NULL)
	{
		ft_printf("Program terminated due to PID error\n");
		exit(-1);
	}
	if (ac != 3)
	{
		ft_printf("Use this format : ./client SERVER_PID \"MESSAGE\"\n");
		exit(-1);
	}
	if (ft_strlen(av[2]) == 0)
	{
		ft_printf("The message to send is empty, nothing was done\n");
		exit(-1);
	}
}

void	send_byte(char c)
{
	if (c & g_infos.shift)
	{
		if (kill(g_infos.server_pid, SIGUSR1) == -1)
			parsing_minitalk(-1, NULL);
	}
	else
	{
		if (kill(g_infos.server_pid, SIGUSR2) == -1)
			parsing_minitalk(-1, NULL);
	}
	g_infos.shift >>= 1;
}

void	send_char(void)
{
	g_infos.shift = 128;
	if (g_infos.cursor == -1)
	{
		ft_printf("Message received by the server !\n");
		exit (0);
	}
	send_byte(g_infos.message[g_infos.cursor]);
}

void	client_signal(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_printf("Program terminated due to server error\n");
		exit (-1);
	}
	if (sig == SIGUSR2)
	{
		if (g_infos.shift == 0)
		{
			if (g_infos.message[g_infos.cursor] == '\0')
				g_infos.cursor = -1;
			else
				g_infos.cursor += 1;
			send_char();
		}
		else
			send_byte(g_infos.message[g_infos.cursor]);
	}
}

int	main(int ac, char **av)
{
	parsing_minitalk(ac, av);
	g_infos.server_pid = ft_atoi(av[1]);
	if (g_infos.server_pid <= 0)
		parsing_minitalk(-1, NULL);
	g_infos.message = av[2];
	signal(SIGUSR1, client_signal);
	signal(SIGUSR2, client_signal);
	send_char();
	while (1)
		;
	return (0);
}
