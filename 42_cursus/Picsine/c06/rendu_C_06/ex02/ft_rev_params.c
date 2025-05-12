/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 10:29:40 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/18 12:53:53 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_tab(int ac, char **av)
{
	int		i;
	char	*str;

	i = 1;
	while (i <= (ac / 2))
	{
		str = av[i];
		av[i] = av[ac - i];
		av[ac - i] = str;
		i++;
	}
}

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

int	ft_rev_params(int ac, char **av)
{
	ft_rev_tab(ac, av);
	ft_print_params(av);
	return (0);
}

int	main(int ac, char **av)
{
	ft_rev_params(ac, av);
	return (0);
}
