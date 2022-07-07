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

int	biggest(t_ps_list *stack)
{
	int biggest;

	biggest = stack->content;
	while (stack != NULL)
	{
		if (stack->content > biggest)
			biggest = stack->content;
		stack = stack->next;
	}
	return (biggest);
}

int	smallest_bis(t_ps_list *stack, int value)
{
	int	smallest_bis;

	smallest_bis = 2147483647;
	while (stack != NULL)
	{
		if (stack->content < smallest_bis && stack->content > value)
			smallest_bis = stack->content;
		stack = stack->next;
	}
	return (smallest_bis);
}

int	biggest_bis(t_ps_list *stack, int value)
{
	int	biggest_bis;

	biggest_bis = -2147483648;
	while (stack != NULL)
	{
		if (stack->content > biggest_bis && stack->content < value)
			biggest_bis = stack->content;
		stack = stack->next;
	}
	return (biggest_bis);
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

t_ps_list	*ft_ps_lstlast(t_ps_list *stack)
{
	while (stack != NULL && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_ps_list	*sort_stack(t_ps_list *stack)
{
	t_ps_list	*sorted_stack;
	t_ps_list	*tmp_lst;
	int			i;
	int			stack_count;

	i = smallest(stack);
	sorted_stack = NULL;
	stack_count = stack_size(stack);
	while (stack_count != stack_size(sorted_stack))
	{
		tmp_lst = ft_ps_lstnew(i);
		if (tmp_lst == NULL)
		{
			ft_ps_lstclear(&sorted_stack); //check if it really works
			ft_putendl_fd("Error alloc", 2);
			return (NULL);
		}
		ft_ps_lstadd_back(&sorted_stack, tmp_lst);
		i = smallest_bis(stack, i);
	}
	return (sorted_stack);
}

int	median_value(t_ps_list *stack, int value)
{
	int	i;

	i = -1;
	while (++i < value)
	{
		stack = stack->next;
	}
	return (stack->content);
}

int	find_median(t_ps_list *stack)
{
	t_ps_list	*sorted_stack;
	int			median;
	int			median_place;

	sorted_stack = sort_stack(stack);
	median_place = stack_size(stack) / 2;
	median = median_value(sorted_stack, median_place);
//
	print_stack(sorted_stack, "sorted_stack");
	ft_printf("median is %i\n", median);
//
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
	print_stack(*stack_a, "stack_a");
	print_stack(*stack_b, "stack_b");
}

void	sort(t_ps_list **stack_a, t_ps_list **stack_b)
{
	int	median;

	median = find_median(*stack_a); //maybe put it directly under
	first_triage(stack_a, stack_b, median);

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
//
	exit(0);
//
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
