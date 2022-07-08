/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:45:39 by mgirardo          #+#    #+#             */
/*   Updated: 2022/07/08 16:45:41 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

void	super_rotate(t_pair	the_pair, t_ps_list **stack_a, t_ps_list **stack_b)
{
	while (the_pair.nb_ra != 0)
	{
		rotate_a(stack_a);
		the_pair.nb_ra--;
	}
	while (the_pair.nb_rb != 0)
	{
		rotate_b(stack_b);
		the_pair.nb_rb--;
	}
	while (the_pair.nb_rr != 0)
	{
		double_rotate(stack_a, stack_b);
		the_pair.nb_rr--;
	}
}

void	super_rev_rot(t_pair the_pair, t_ps_list **stack_a, t_ps_list **stack_b)
{
	while (the_pair.nb_rra != 0)
	{
		reverse_a(stack_a);
		the_pair.nb_rra--;
	}
	while (the_pair.nb_rrb != 0)
	{
		reverse_b(stack_b);
		the_pair.nb_rrb--;
	}
	while (the_pair.nb_rrr != 0)
	{
		double_reverse_rotate(stack_a, stack_b);
		the_pair.nb_rrr--;
	}
}

void	to_clear(t_pair **pairs, t_ps_list **stack_a, t_ps_list **stack_b)
{
	ft_pair_lstclear(pairs);
	ft_ps_lstclear(stack_a);
	ft_ps_lstclear(stack_b);
	ft_putendl_fd("Error", 2);
}
