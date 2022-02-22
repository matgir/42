/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 14:13:36 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/18 16:30:31 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_print_program_name(char **av)
{
	unsigned int	i;

	i = 0;
	while (av[0][i])
	{
		write (1, &av[0][i], 1);
		i++;
	}
	write (1, "\n", 1);
	return (0);
}

int	main(int ac, char **av)
{
	(void) ac;
	ft_print_program_name(av);
	return (0);
}
