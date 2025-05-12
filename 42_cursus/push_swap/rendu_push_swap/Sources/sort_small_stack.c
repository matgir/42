/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:25:16 by mgirardo          #+#    #+#             */
/*   Updated: 2022/07/07 11:25:19 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

void	sort_three(t_ps_list **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->content;
	second = (*stack)->next->content;
	third = (*stack)->next->next->content;
	if (first < second && first < third)
	{
		reverse_a(stack);
		swap_a(stack);
	}
	if (first > second && first < third)
		swap_a(stack);
	if (first < second && first > third)
		reverse_a(stack);
	if (first > second && second > third && first > third)
	{
		rotate_a(stack);
		swap_a(stack);
	}
	if (first > second && first > third && second < third)
		rotate_a(stack);
}

void	sort_four(t_ps_list **stack_a, t_ps_list **stack_b)
{
	to_the_top(stack_a, smallest(*stack_a), 'a');
	push_b(stack_a, stack_b);
	if (is_it_good(stack_a) != 0)
		sort_three(stack_a);
	push_a(stack_a, stack_b);
}

void	sort_five(t_ps_list **stack_a, t_ps_list **stack_b)
{
	to_the_top(stack_a, smallest(*stack_a), 'a');
	push_b(stack_a, stack_b);
	if (is_it_good(stack_a) != 0)
		sort_four(stack_a, stack_b);
	push_a(stack_a, stack_b);
}
