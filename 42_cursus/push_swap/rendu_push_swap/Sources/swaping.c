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

t_pair	pairs(t_ps_list **stack_a, t_ps_list **stack_b)
{
	t_pair		*pairs;
	t_pair		*tmp_pair;
	int			c_a;
	t_ps_list	*tmp_sb;
	t_pair		the_pair;

	tmp_sb = *stack_b;
	pairs = NULL;
	while (tmp_sb != NULL)
	{
		c_a = smallest_bis(*stack_a, tmp_sb->content);
		tmp_pair = ft_pair_lstnew(c_a, tmp_sb->content, nb_move(*stack_a, c_a),
				nb_move(*stack_b, tmp_sb->content));
		if (tmp_pair == NULL)
		{
			ft_pair_lstclear(&pairs);
			ft_ps_lstclear(stack_a);
			ft_ps_lstclear(stack_b);
			ft_putendl_fd("Error", 2);
			exit(-1);
		}
		ft_pair_lstadd_back(&pairs, tmp_pair);
		tmp_sb = tmp_sb->next;
	}
	the_pair = costless_pair(pairs);
	ft_pair_lstclear(&pairs);
	return (the_pair);
}

void	to_move_a_pair(t_ps_list **stack_a, t_ps_list **stack_b)
{
	t_pair	the_pair;

	the_pair = pairs(stack_a, stack_b);
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

void	sort(t_ps_list **stack_a, t_ps_list **stack_b)
{
	int	median;

	median = find_median(stack_a);
	first_triage(stack_a, stack_b, median);
	while ((*stack_b) != NULL)
	{
		to_move_a_pair(stack_a, stack_b);
		push_a(stack_a, stack_b);
	}
	to_the_top(stack_a, smallest(*stack_a), 'a');
}

void	start_sort(t_ps_list **stack_a, t_ps_list **stack_b)
{
	int	stack_count;

	stack_count = stack_size(*stack_a);
	if (stack_count == 2)
		swap_a(stack_a);
	else if (stack_count == 3)
		sort_three(stack_a);
	else if (stack_count == 4)
		sort_four(stack_a, stack_b);
	else if (stack_count == 5)
		sort_five(stack_a, stack_b);
	else
		sort(stack_a, stack_b);
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
