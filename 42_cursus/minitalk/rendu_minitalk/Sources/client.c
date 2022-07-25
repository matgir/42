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
/*
int	main(int ac, char **av)
{
	if (ac != 3)
		return (ft_printf
			("Please use this format : \"./client SERVER_PID MESSAGE\"\n"));

	int i = 0;
	while (av[2][i] != 0)
	{
		ft_printf("%c\n", av[2][i]);
		av[2][i] >>= 1;
	}
	return (0);
}
*/

int	send_char(unsigned char c, pid_t pid, int slp_time)
{
	int	i;
	int	tmp;
	int	kill_status;

	i = 1;
	tmp = c;
	while (i <= 8)
	{
		if (tmp % 2 == 1)
			kill_status = kill(pid, SIGUSR2);
		else
			kill_status = kill(pid, SIGUSR1);
		tmp >>= 1;
		i++;
		if (kill_status == -1)
			return (-1);
		usleep(slp_time);
	}
	return (0);
}

int	print_err(char *s)
{
	ft_putstr_fd(s, 2);
	return (1);
}

void	send_str(unsigned char *str, pid_t pid, int status)
{
	int	i;
	int	slp_time;

	if (ft_strlen((char *)str) <= 3000)
		slp_time = 40;
	else
		slp_time = 125;
	i = 0;
	while (str[i])
	{
		if (send_char(str[i], pid, slp_time) == -1)
		{
			free(str);
			exit (print_err("Kill failed, surely bad PID imput\n"));
		}
		i++;
	}
	if (status == NO_EMPTY)
		send_char(0, pid, 30);
	else
		kill(pid, SIGUSR1);
}

void	error_pid_client(pid_t pid)
{
	if (pid <= 100 || pid >= 99998)
		exit (print_err("Invalid PID\n"));
}

unsigned char	*build_tab(char **argv)
{
	unsigned char	*to_free;
	unsigned char	*tab;
	char			*itoa_tab;

	itoa_tab = ft_itoa(getpid());
	tab = (unsigned char *)ft_strjoin(itoa_tab, "|");
	free(itoa_tab);
	to_free = tab;
	tab = (unsigned char *)ft_strjoin("|", (char *)tab);
	free(to_free);
	to_free = tab;
	itoa_tab = ft_itoa(ft_strlen(argv[2]));
	tab = (unsigned char *)ft_strjoin(itoa_tab, (char *)tab);
	free(to_free);
	free(itoa_tab);
	to_free = tab;
	tab = (unsigned char *)ft_strjoin((char *)tab, argv[2]);
	free(to_free);
	return (tab);
}

unsigned char	*build_tab_empty(void)
{
	unsigned char	*to_free;
	unsigned char	*tab;
	char			*itoa_tab;

	itoa_tab = ft_itoa(getpid());
	tab = (unsigned char *)ft_strjoin(itoa_tab, "|");
	free(itoa_tab);
	to_free = tab;
	tab = (unsigned char *)ft_strjoin("|", (char *)tab);
	free(to_free);
	return (tab);
}

int	main(int argc, char **argv)
{
	unsigned char		*tab;
	int					pid;

	if (argc != 3)
		exit(print_err("Must be: ./cilent <server_PID> <message>\n"));
	if (ft_strlen(argv[2]) != 0)
		tab = build_tab(argv);
	else
		tab = build_tab_empty();
	/*if (ft_strlen(argv[1]) >= 6)
		exit (print_err("Invalid PID\n"));
	*/pid = ft_atoi(argv[1]);
	//error_pid_client(pid);
	if (ft_strlen(argv[2]) != 0)
		send_str(tab, pid, NO_EMPTY);
	else
		send_str(tab, pid, EMPTY);
	return (0);
}