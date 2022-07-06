/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 16:22:49 by mgirardo          #+#    #+#             */
/*   Updated: 2022/07/06 16:22:52 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

int	reverse_rotate(t_ps_list **stack)
{
	t_ps_list	*tmp;
	t_ps_list	*last;

	tmp = *stack;
	if (tmp == NULL || tmp->next == NULL)
		return (1);
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = *stack;
	*stack = last;
	return (0);
}

void	reverse_a(t_ps_list **stack_a)
{
	if (reverse_rotate(stack_a) == 0)
		ft_putendl_fd("rra", 1);
}

void	reverse_b(t_ps_list **stack_b)
{
	if (reverse_rotate(stack_b) == 0)
		ft_putendl_fd("rrb", 1);
}

void	double_reverse_rotate(t_ps_list **stack_a, t_ps_list **stack_b)
{
	if ((*stack_a)->next == NULL || (*stack_b)->next == NULL)
	{
		if (reverse_rotate(stack_b) == 0 || reverse_rotate(stack_a) == 0)
			ft_putendl_fd("rr", 1);
	}
	else
	{
		if (reverse_rotate(stack_b) == 0 && reverse_rotate(stack_a) == 0)
			ft_putendl_fd("rr", 1);
	}
}
