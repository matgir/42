/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 14:51:52 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/24 10:17:28 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	unsigned int	j;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	j = nb - 1;
	while (j > 0)
	{
		nb = nb * j;
		j--;
	}
	return (nb);
}
