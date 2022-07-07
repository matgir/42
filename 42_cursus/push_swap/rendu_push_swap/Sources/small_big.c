/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_big.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:19:44 by mgirardo          #+#    #+#             */
/*   Updated: 2022/07/07 18:19:46 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

int	smallest(t_ps_list *stack)
{
	int	smallest;

	smallest = stack->content;
	while (stack != NULL)
	{
		if (stack->content < smallest)
			smallest = stack->content;
		stack = stack->next;
	}
	return (smallest);
}

int	biggest(t_ps_list *stack)
{
	int biggest;

	biggest = stack->content;
	while (stack != NULL)
	{
		if (stack->content > biggest)
			biggest = stack->content;
		stack = stack->next;
	}
	return (biggest);
}

int	smallest_bis(t_ps_list *stack, int value)
{
	int	smallest_bis;

	smallest_bis = 2147483647;
	while (stack != NULL)
	{
		if (stack->content < smallest_bis && stack->content > value)
			smallest_bis = stack->content;
		stack = stack->next;
	}
	return (smallest_bis);
}

int	biggest_bis(t_ps_list *stack, int value)
{
	int	biggest_bis;

	biggest_bis = -2147483648;
	while (stack != NULL)
	{
		if (stack->content > biggest_bis && stack->content < value)
			biggest_bis = stack->content;
		stack = stack->next;
	}
	return (biggest_bis);
}