/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 16:54:33 by mgirardo          #+#    #+#             */
/*   Updated: 2022/08/03 16:54:35 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libminitalk.h"

t_to_print	g_infos;

void	reset_bits(void)
{
	g_infos.bits[0] = -1;
	g_infos.bits[1] = -1;
	g_infos.bits[2] = -1;
	g_infos.bits[3] = -1;
	g_infos.bits[4] = -1;
	g_infos.bits[5] = -1;
	g_infos.bits[6] = -1;
	g_infos.bits[7] = -1;
}

void	join_char(char c)
{
	g_infos.to_print = ft_mntlk_strjoin(g_infos.to_print, c);
	if (!(g_infos.to_print))
	{
		ft_printf("Allocation problem, server stopped\n");
		if (kill(g_infos.client_pid, SIGUSR1) == -1)
			ft_printf("Error could not be sent to client\n");
		exit(1);
	}
}

char	bits_to_char(t_to_print g_infos)
{
	char	charact;
	int		shift;
	int		i;

	charact = 0;
	i = 0;
	shift = 128;
	while (shift)
	{
		charact += g_infos.bits[i] * shift;
		i++;
		shift >>= 1;
	}
	return (charact);
}

void	get_bits(int sig, int cursor)
{
	char	c;

	if (sig == SIGUSR2)
		g_infos.bits[cursor] = 0;
	if (sig == SIGUSR1)
		g_infos.bits[cursor] = 1;
	if (cursor == 7)
	{
		c = bits_to_char(g_infos);
		if (c == '\0')
		{
			ft_printf("\n\nMessage from client PID :%i\n\n", g_infos.client_pid);
			ft_putstr_fd(g_infos.to_print, 1);
			free(g_infos.to_print);
			g_infos.to_print = NULL;
		}
		else
			join_char(c);
		reset_bits();
	}
}

void	server_signal(int sig, siginfo_t *siginfo, void *ucontext)
{
	int		cursor;
	int		i;

	(void) ucontext;
	g_infos.client_pid = siginfo->si_pid;
	i = -1;
	cursor = 0;
	while (++i < 8)
	{
		if (g_infos.bits[i] == -1)
		{
			cursor = i;
			break ;
		}
	}
	get_bits(sig, cursor);
	if (kill(g_infos.client_pid, SIGUSR2) == -1)
	{
		free(g_infos.to_print);
		g_infos.to_print = NULL;
		ft_printf("\n\nConfirmation could not be sent to client\n");
	}
}
