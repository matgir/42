/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 15:48:46 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/19 13:30:14 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	not_good(char *base)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (base[i])
	{
		if (base[i] < ' ' || base[i] == '+' || base[i] == '-' || base[i] > '~')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	i;
	long int		nb;

	nb = nbr;
	i = 0;
	while (base[i])
		i++;
	if (i < 2)
		return ;
	if (not_good(base) == 0)
		return ;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * -1;
	}
	if ((unsigned int)nb > i - 1)
	{
		ft_putnbr_base((nb / i), base);
		ft_putnbr_base((nb % i), base);
	}
	else
		(ft_putchar(base[nb % i]));
}
