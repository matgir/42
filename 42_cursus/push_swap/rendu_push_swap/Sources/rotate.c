/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:56:55 by mgirardo          #+#    #+#             */
/*   Updated: 2022/07/06 15:56:57 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

int	rotate(t_ps_list **stack)
{
	t_ps_list	*tmp;
	t_ps_list	*second;

	tmp = *stack;
	if (tmp == NULL || tmp->next == NULL)
		return (1);
	*stack = tmp->next;
	second = *stack;
	while (second->next != NULL)
		second = second->next;
	second->next = tmp;
	tmp->next = NULL;
	return (0);
}

void	rotate_a(t_ps_list **stack_a)
{
	if (rotate(stack_a) == 0)
		ft_putendl_fd("ra", 1);
}

void	rotate_b(t_ps_list **stack_b)
{
	if (rotate(stack_b) == 0)
		ft_putendl_fd("rb", 1);
}

void	double_rotate(t_ps_list **stack_a, t_ps_list **stack_b)
{
	if ((*stack_a)->next == NULL || (*stack_b)->next == NULL)
	{
		if (rotate(stack_b) == 0 || rotate(stack_a) == 0)
			ft_putendl_fd("rr", 1);
	}
	else
	{
		if (rotate(stack_b) == 0 && rotate(stack_a) == 0)
			ft_putendl_fd("rr", 1);
	}
}
