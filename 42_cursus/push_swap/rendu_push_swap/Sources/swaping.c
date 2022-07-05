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

void	swap_a(t_ps_list **stack_a, t_ps_list **stack_b)
{
	t_ps_list	*tmp;

	if (*stack_b == NULL)
	{
		*stack_b = *stack_a;
		*stack_a = *(stack_a->next);
		*(stack_b->next) = NULL;
	}
	else
	{
		tmp = *stack_a;
		tmp->next = *stack_b;
		*stack_a = *(stack_a->next);
	}
}

void	swaping(t_ps_list **stack_a)
{
	t_ps_list	*stack_b;

	stack_b = NULL;
}
