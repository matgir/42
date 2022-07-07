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
//
	int	i = 0;
//
	if (place(*stack, value) <= stack_size(*stack) / 2)
	{
		while ((*stack)->content != value)
		{
//
			i++;
//
			rotate_b(stack);
		}
	}
	else
	{
		while ((*stack)->content != value)
		{
//
			i++;
//
			reverse_b(stack);
		}
	}
}

void	to_the_top_a(t_ps_list **stack, int value)
{
//
	int	i = 0;
//
	if (place(*stack, value) <= stack_size(*stack) / 2)
	{
		while ((*stack)->content != value)
		{
//
			i++;
//
			rotate_a(stack);
		}
	}
	else
	{
		while ((*stack)->content != value)
		{
//
			i++;
//
			reverse_a(stack);
		}
	}
	ft_printf("nb move %i\n", i);
}

void	to_the_top(t_ps_list **stack, int value, char which)
{
	ft_printf("place is %i\n", place(*stack, value));
	
	//equation to find nb move to go to the top;
	
	if (place(*stack, value) <= stack_size(*stack) / 2)
		ft_printf("nb move %i\n", place(*stack, value)); // et donc RA
	else
		ft_printf("nb move %i\n", (stack_size(*stack) - place(*stack, value))); // et donc RRa



	if (which == 'a')
		to_the_top_a(stack, value);
	if (which == 'b')
		to_the_top_b(stack, value);
}