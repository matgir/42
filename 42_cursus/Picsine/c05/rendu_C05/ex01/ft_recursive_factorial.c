/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 17:31:11 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/18 16:31:51 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	j;

	j = nb;
	if (nb < 0)
		return (0);
	if (nb == 1 || nb == 0)
		return (1);
	if (j > 1)
		nb = j * ft_recursive_factorial(nb - 1);
	return (nb);
}
