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

char	*ft_mntlk_strjoin(char *str, char c)
{
	char	*join;
	size_t	i;
	size_t	u;

	i = ft_strlen(str);
	join = malloc(sizeof(char) * (i + 2));
	if (join == NULL)
		return (NULL);
	u = 0;
	while (i != 0)
	{
		join[u] = str[u];
		u++;
		i--;
	}
	join[u++] = c;
	join[u] = '\0';
	free(str);
	return (join);
}

int	main(int ac, char **av)
{
	t_sigation	sa;

	(void)av;
	if (ac != 1)
	{
		ft_printf("Use this format : ./server\n");
		exit(-1);
	}
	reset_bits();
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = server_signal;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGINT);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("Server started with PID : %i !", getpid());
	while (1)
		;
}
