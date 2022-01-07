/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ck_arg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tliot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 19:09:31 by tliot             #+#    #+#             */
/*   Updated: 2021/08/15 19:12:07 by tliot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int	ph(char *str);
int	pl(char *str);
int	rgl(char *str);

int	ft_len(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	sp(char *str)
{
	unsigned int	i;

	i = 1;
	while (str[i])
	{
		if (str[i] != ' ')
			return (1);
		i += 2;
	}
	return (0);
}

int	nb(char *str)
{
	unsigned int	i;

	i = 0;
	while (i < 31)
	{
		if (str[i] < '1' || str[i] > '4')
			return (1);
		i += 2;
	}
	return (0);
}

int	ck_arg(int ac, char **av)
{
	char	*str;

	str = av[1];
	if (ac != 2 || ft_len(str) != 31 || sp(str) == 1 || nb(str) == 1)
	{
		write(1, "Error", 5);
		return (1);
	}
	if (ph(str) == 1 || pl(str) == 1 || rgl(str) == 1)
	{
		write(1, "Error", 5);
		return (1);
	}
	return (0);
}
