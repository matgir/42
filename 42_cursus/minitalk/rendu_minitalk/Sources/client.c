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

t_to_send	infos;

void	parsing_minitalk(int ac, char **av)
{
	if (ac != 3)
	{
		ft_printf("Please use this format : \"./client SERVER_PID MESSAGE\"\n");
		exit(-1);
	}
	if (ft_strlen(av[2]) == 0)
	{
		ft_printf("The message to send is empty, nothing was done\n");
		exit(-1);
	}
}

int	main(int ac, char **av)
{
	parsing_minitalk(ac, av);
	infos.server_pid = ft_atoi(av[1]);
	infos.message = 
	return (0);
}






#include "libminitalk.h"

t_send	g_send_infos;

void	send_error(void)
{
	ft_printf("Error encountered during the message's transmission. ");
	ft_printf("This is probably due to a bad PID\n");
	exit(1);
}

void	send_next_byte(int pid, unsigned char c)
{
	if (c & g_send_infos.binary)
	{
		if (kill(pid, SIGUSR2) == -1)
			send_error();
	}
	else
	{
		if (kill(pid, SIGUSR1) == -1)
			send_error();
	}
	g_send_infos.binary >>= 1;
}

void	send_next_char(void)
{
	g_send_infos.binary = 128;
	if (g_send_infos.current == -1)
	{
		ft_printf("The whole message whas received by the server !\n");
		exit(0);
	}
	send_next_byte(g_send_infos.pid,
		(unsigned char) g_send_infos.str[g_send_infos.current]);
}

void	signal_handler_c(int signum)
{
	if (signum == SIGUSR1)
	{
		ft_printf("The server notified an error during message's reception !\n");
		exit(1);
	}
	if (signum == SIGUSR2)
	{
		if (g_send_infos.binary == 0)
		{
			if (g_send_infos.str[g_send_infos.current] == '\0')
				g_send_infos.current = -1;
			else
				g_send_infos.current = g_send_infos.current + 1;
			send_next_char();
		}
		else
			send_next_byte(g_send_infos.pid,
				g_send_infos.str[g_send_infos.current]);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		ft_printf("Please use client with this format: ");
		ft_printf("./client SERVER_PID \"MESSAGE\"\n");
		return (1);
	}
	signal(SIGUSR1, signal_handler_c);
	signal(SIGUSR2, signal_handler_c);
	g_send_infos.pid = ft_atoi(argv[1]);
	g_send_infos.str = argv[2];
	g_send_infos.current = 0;
	if (g_send_infos.str[0])
		ft_printf("Sending message to PID %i ...\n", g_send_infos.pid);
	else
		ft_printf("Sending quit signal to PID %i ...\n", g_send_infos.pid);
	send_next_char();
	while (TRUE)
		;
}