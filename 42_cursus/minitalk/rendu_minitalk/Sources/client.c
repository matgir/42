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

int	main(int ac, char **av)
{
	if (ac != 3)
		return (ft_printf
			("Please use this format : ./client SERVER_PID \"MESSAGE\"\n"));

	int i = 0;
	while (av[2][i] != 0)
	{
		ft_printf("%c\n", av[2][i]);
		av[2][i] >>= 1;
	}
	return (0);
}
