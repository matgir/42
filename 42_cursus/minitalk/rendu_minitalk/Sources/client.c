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

void	parsing_minitalk(int ac, char **av)
{
	if (ac != 3)
	{
		ft_printf("Please use this format : \"./client SERVER_PID MESSAGE\"\n");
		return;
	}
	if (ft_strlen(av[2]) == 0)
	{
		ft_printf("The message to send is empty, nothing was done\n");
		return;
	}
}

int	main(int ac, char **av)
{
	parsing_minitalk(ac, av);
	pid_t	server_pid = ft_atoi(av[1]);
	return (0);
}
