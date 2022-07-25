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
/*
int	main(void)
{
	ft_printf("Server PID : %i\n", getpid());
}

*/
int	sig_to_char(int sig)
{
	static unsigned char	c;
	static int				count;
	unsigned char			tmp;

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

int	print_err(char *s)
{
	ft_putstr_fd(s, 2);
	return (1);
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
	char			*final_string = NULL;
	static pid_t	pid;
	static int		len;

	(void)truc;
	(void)context;
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