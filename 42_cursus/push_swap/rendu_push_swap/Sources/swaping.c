/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:53:59 by mgirardo          #+#    #+#             */
/*   Updated: 2022/07/05 17:58:42 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

int	stack_size(t_ps_list *stack)
{
	int	count;

	count = 0;
	while (stack != NULL)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

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

int	place(t_ps_list *stack, int value)
{
	int index;

	index = 0;
	while (stack != NULL)
	{
		if (stack->content == value)
			return (index);
		index++;
		stack = stack->next;
	}
	return (-1);
}

void	to_the_top_b(t_ps_list **stack, int value)
{
	if (place(*stack, value) + 1 <= stack_size(*stack) / 2)
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
	if (place(*stack, value) + 1 <= stack_size(*stack) / 2)
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

void	sort_four(t_ps_list **stack_a, t_ps_list **stack_b)
{
	to_the_top(stack_a, smallest(*stack_a), 'a');
	push_b(stack_a, stack_b);
	sort_three(stack_a);
	push_a(stack_a, stack_b);
}

void	start_sort(t_ps_list **stack_a, t_ps_list **stack_b)
{
	int	stack_count;

				stack_count = stack_size(*stack_b);

	stack_count = stack_size(*stack_a);
	if (stack_count == 2)
		swap_a(stack_a);
	else if (stack_count == 3)
		sort_three(stack_a);
	else if (stack_count == 4)
		sort_four(stack_a, stack_b);
}

int	swaping(t_ps_list **stack_a)
{
	t_ps_list	*stack_b;

	stack_b = NULL;
	while (1)
	{
		if (stack_b == NULL && is_it_good(stack_a) == 0)
			return (0);
		start_sort(stack_a, &stack_b);
	}
	return (1);
}
