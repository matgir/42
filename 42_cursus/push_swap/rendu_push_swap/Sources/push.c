/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:42:03 by mgirardo          #+#    #+#             */
/*   Updated: 2022/07/06 14:42:06 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

int	push(t_ps_list **from, t_ps_list **to)
{
	t_ps_list	*tmp;

	if (*from == NULL)
		return (1);
	tmp = *from;
	*from = tmp->next;
	tmp->next = *to;
	*to = tmp;
	return (0);
}

void	push_b(t_ps_list **stack_a, t_ps_list **stack_b)
{
	if (push(stack_a, stack_b) == 0)
		ft_putendl_fd("pb", 1);
}

void	push_a(t_ps_list **stack_a, t_ps_list **stack_b)
{
	if (push(stack_b, stack_a) == 0)
		ft_putendl_fd("pa", 1);
}
