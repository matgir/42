/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:30:33 by mgirardo          #+#    #+#             */
/*   Updated: 2022/07/19 18:30:36 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sources/libminitalk.h"

/*##########  server  ##########*/

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
	struct sigaction	sa;

	ft_printf("Server PID : %i\n", getpid());
	sa.sa_sigaction = action;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
		pause();
	return(0);
}

/*##########  client  ##########*/

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









/*##########  server  ##########*/

int	sig_to_char(int sig)
{
	static unsigned char	c;
	static int				count;
	unsigned char			tmp;
	static int				i;

	tmp = 0;
	if (count < 8 && (sig == SIGUSR1 || sig == SIGUSR2))
	{
		if (sig == SIGUSR2)
			tmp = 1;
		tmp = tmp << count;
		c |= tmp;
		count++;
	}
	if (count == 8)
	{
		count = 0;
		tmp = c;
		c = 0;
		return (tmp);
	}
	return (-1);
}

int	get_pre_signal(int sig)
{
	static char	len_or_pid[10];
	static int	i;
	int			c;

	c = sig_to_char(sig);
	if (c != -1)
	{
		len_or_pid[i] = (char)c;
		i++;
	}
	if (c == 124)
	{
		i = 0;
		return (ft_atoi(len_or_pid));
	}
	return (-1);
}

char	*get_string_in_signal(int sig, int len)
{
	static int	i;
	static int	first_entry;
	int			c;
	static char	*str;

	c = sig_to_char(sig);
	if (len == 0 && c != -1)
		return (ft_strdup(""));
	if (first_entry == 0)
	{
		str = ft_calloc(sizeof(char), len + 1);
		first_entry = 1;
	}
	if (c != -1)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	if (c == 0)
	{
		first_entry = 0;
		i = 0;
		return (str);
	}
	return (NULL);
}

void	final_step(int *len, int *status, int *pid, char *final_string)
{
	if (*len != 0)
	{
		ft_printf("%s", final_string);
		free(final_string);
	}
	*status = 0;
	*pid = -1;
	*len = -1;
}

int	error_pid(pid_t pid)
{
	if (pid == -1)
		return (1);
	if (pid <= 100 || pid >= 99998)
		exit (print_err("Invalid PID\n"));
	return (2);
}

void	get_sig(int sig, siginfo_t *truc, void *context)
{
	static int		status;
	char			*final_string;
	static pid_t	pid;
	static int		len;

	if (status == 0)
	{
		len = get_pre_signal(sig);
		if (len != -1)
			status = 1;
		return ;
	}
	if (status == 1)
	{
		pid = get_pre_signal(sig);
		status = error_pid(pid);
		if (len == 0 && status == 2)
			status = 3;
		return ;
	}
	if (status == 2)
		final_string = get_string_in_signal(sig, len);
	if (final_string == NULL)
		return ;
	final_step(&len, &status, &pid, final_string);
}

int	print_err(char *s)
{
	ft_putstr_fd(s, 2);
	return (1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID : %i\n", getpid());
	sa.sa_sigaction = get_sig;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
	}
}

/*##########  client  ##########*/

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

int	print_err(char *s)
{
	ft_putstr_fd(s, 2);
	return (1);
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
	unsigned char		c;
	unsigned char		*tab;
	int					pid;

	if (argc != 3)
		exit(print_err("Must be: ./cilent <server_PID> <message>\n"));
	if (ft_strlen(argv[2]) != 0)
		tab = build_tab(argv);
	else
		tab = build_tab_empty();
	if (ft_strlen(argv[1]) >= 6)
		exit (print_err("Invalid PID\n"));
	pid = ft_atoi(argv[1]);
	error_pid_client(pid);
	if (ft_strlen(argv[2]) != 0)
		send_str(tab, pid, NO_EMPTY);
	else
		send_str(tab, pid, EMPTY);
	return (0);
}