/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_the_top.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 12:33:47 by mgirardo          #+#    #+#             */
/*   Updated: 2022/07/07 12:33:48 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

void	to_the_top_b(t_ps_list **stack, int value)
{
	if (place(*stack, value) <= stack_size(*stack) / 2)
	{
		while ((*stack)->content != value)
			rotate_b(stack);
	}
	else
	{
		while ((*stack)->content != value)
			reverse_b(stack);
	}
}

void	to_the_top_a(t_ps_list **stack, int value)
{
	if (place(*stack, value) <= stack_size(*stack) / 2)
	{
		while ((*stack)->content != value)
			rotate_a(stack);
	}
	else
	{
		while ((*stack)->content != value)
			reverse_a(stack);
	}
}

void	to_the_top(t_ps_list **stack, int value, char which)
{
	if (which == 'a')
		to_the_top_a(stack, value);
	if (which == 'b')
		to_the_top_b(stack, value);
}
