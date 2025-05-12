/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:23:28 by mgirardo          #+#    #+#             */
/*   Updated: 2022/07/07 18:23:31 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

t_ps_list	*sort_stack(t_ps_list **stack)
{
	t_ps_list	*sorted_stack;
	t_ps_list	*tmp_lst;
	int			i;
	int			stack_count;

	i = smallest(*stack);
	sorted_stack = NULL;
	stack_count = stack_size(*stack);
	while (stack_count != stack_size(sorted_stack))
	{
		tmp_lst = ft_ps_lstnew(i);
		if (tmp_lst == NULL)
		{
			ft_ps_lstclear(&sorted_stack);
			ft_ps_lstclear(stack);
			ft_putendl_fd("Error", 2);
			exit (-1);
		}
		ft_ps_lstadd_back(&sorted_stack, tmp_lst);
		i = smallest_bis(*stack, i);
	}
	return (sorted_stack);
}

int	median_value(t_ps_list *stack, int place)
{
	int	i;

	i = 0;
	while (i < place)
	{
		stack = stack->next;
		i++;
	}
	return (stack->content);
}

int	find_median(t_ps_list **stack)
{
	t_ps_list	*sorted_stack;
	int			median;
	int			median_place;

	sorted_stack = sort_stack(stack);
	median_place = stack_size(*stack) / 2;
	median = median_value(sorted_stack, median_place);
	ft_ps_lstclear(&sorted_stack);
	return (median);
}

void	first_triage(t_ps_list **stack_a, t_ps_list **stack_b, int median)
{
	int		big;
	int		big_bis;

	big = biggest(*stack_a);
	big_bis = biggest_bis(*stack_a, big);
	while (stack_size(*stack_a) != 2)
	{
		if ((*stack_a)->content < median)
			push_b(stack_a, stack_b);
		else if ((*stack_a)->content != big && (*stack_a)->content != big_bis)
		{
			push_b(stack_a, stack_b);
			double_rotate(stack_a, stack_b);
		}
		else
			rotate_a(stack_a);
	}
}
