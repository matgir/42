/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 11:38:04 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/18 12:54:41 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	j;

	j = 0;
	while (s1[j] || s2[j])
	{
		if (s1[j] > s2[j] || s1[j] < s2[j])
			return (s1[j] - s2[j]);
		if (s1[j] == s2[j])
			j++;
	}
	return (0);
}

void	ft_sort_tab(int ac, char **av)
{
	int		i;
	int		n;
	char	*str;

	i = 1;
	while (i < ac)
	{
		n = i + 1;
		while (n < ac)
		{
			if (ft_strcmp(av[i], av[n]) > 0)
			{
				str = av[i];
				av[i] = av[n];
				av[n] = str;
			}
			n++;
		}
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
			write(1, &av[i][j], 1);
			j++;
		}
		write (1, "\n", 1);
		i++;
	}
	return (0);
}

int	ft_sort_params(int ac, char **av)
{
	ft_sort_tab(ac, av);
	ft_print_params(av);
	return (0);
}

int	main(int ac, char **av)
{
	ft_sort_params(ac, av);
	return (0);
}
