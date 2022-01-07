/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 12:29:55 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/23 15:31:51 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	long int	i;

	if (nb == 2 || nb == 3 || nb == 5)
		return (1);
	if (nb <= 1 || nb % 2 == 0 || nb % 3 == 0 || nb % 5 == 0)
		return (0);
	i = 5;
	while (i * i <= nb)
	{
		if (nb % i == 0 || nb % (i + 2) == 0)
			return (0);
		i += 6;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (ft_is_prime(nb) == 1)
		return (nb);
	else if (nb <= 2)
		return (2);
	else
	{
		while (nb <= 2147483647)
		{
			if (ft_is_prime(nb) == 1)
				return (nb);
			nb++;
		}
	}
	return (nb);
}
