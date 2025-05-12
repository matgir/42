/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:42:23 by mgirardo          #+#    #+#             */
/*   Updated: 2022/07/06 14:42:36 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

int	swap(t_ps_list **stack)
{
	t_ps_list	*tmp;
	t_ps_list	*third;

	tmp = *stack;
	if (tmp == NULL || tmp->next == NULL)
		return (1);
	third = tmp->next->next;
	*stack = tmp->next;
	tmp->next = third;
	(*stack)->next = tmp;
	return (0);
}

void	swap_a(t_ps_list **stack_a)
{
	if (swap(stack_a) == 0)
		ft_putendl_fd("sa", 1);
}

void	swap_b(t_ps_list **stack_b)
{
	if (swap(stack_b) == 0)
		ft_putendl_fd("sb", 1);
}

void	double_swap(t_ps_list **stack_a, t_ps_list **stack_b)
{
	if (*stack_a != NULL && *stack_b != NULL)
	{
		if ((*stack_a)->next == NULL || (*stack_b)->next == NULL)
		{
			if (swap(stack_b) == 0 || swap(stack_a) == 0)
				ft_putendl_fd("ss", 1);
		}
		else
		{
			if (swap(stack_b) == 0 && swap(stack_a) == 0)
				ft_putendl_fd("ss", 1);
		}
	}
}
