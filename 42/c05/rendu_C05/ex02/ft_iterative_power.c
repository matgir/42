/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 20:14:11 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/18 16:32:19 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	j;

	j = nb;
	if (power < 0)
		return (0);
	if ((nb == 0 && power == 0) || power == 0 || nb == 1)
		return (1);
	while (power > 1)
	{
		nb = j * nb;
		power--;
	}
	return (nb);
}
