/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:03:43 by mgirardo          #+#    #+#             */
/*   Updated: 2021/12/20 17:03:53 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_putchar_fd(char c, int i);

int	main(int ac, char **av)
{

	unsigned int	i = 0	;
	(void) ac;

	while (av[1][i])
	{
		ft_putchar_fd(av[1][i], atoi(av[2]));
		i++;
	}
	return (0);
}
