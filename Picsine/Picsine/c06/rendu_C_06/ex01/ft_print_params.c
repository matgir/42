/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 10:14:06 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/18 12:52:15 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_print_params(char **av)
{
	unsigned int	i;
	unsigned int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			write (1, &av[i][j], 1);
			j++;
		}
		write (1, "\n", 1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	(void) ac;
	ft_print_params(av);
	return (0);
}
