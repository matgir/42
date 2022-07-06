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
	if (swap(stack_a) == 0 || swap(stack_b) == 0) //verif si && ou ||
		ft_putendl_fd("ss", 1);
}

int	push(t_ps_list **from, t_ps_list **to)
{
	t_ps_list	*tmp;

	if (*from == NULL)
		return (1);
	if (*to == NULL)
	{
		tmp = *from;
		*from = tmp->next;
		tmp->next = NULL;
		*to = tmp;
	}
	else
	{
		tmp = *from;
		*from = tmp->next;
		tmp->next = *to;
		*to = tmp;
	}
	return (0);
}

void	push_a(t_ps_list **stack_a, t_ps_list **stack_b)
{
	if (push(stack_a, stack_b) == 0)
		ft_putendl_fd("pa", 1);
}

void	push_b(t_ps_list **stack_a, t_ps_list **stack_b)
{
	if (push(stack_b, stack_a) == 0)
		ft_putendl_fd("pb", 1);
}

void	swaping(t_ps_list *stack_a)
{
	t_ps_list	*stack_b;
	t_ps_list	*tmp_a;
	t_ps_list	*tmp_b;

	stack_b = NULL;
	push_a(&stack_a, &stack_b);
	ft_printf("stack_a\n");
	tmp_a = stack_a;
	while (tmp_a != NULL)
	{
		ft_printf("%i\n", tmp_a->content);
		tmp_a = tmp_a->next;
	}
	ft_printf("stack_b\n");
	tmp_b = stack_b;
	while (tmp_b != NULL)
	{
		ft_printf("%i\n", tmp_b->content);
		tmp_b = tmp_b->next;
	}
	double_swap(&stack_a, &stack_b);
	ft_printf("stack_a\n");
	tmp_a = stack_a;
	while (tmp_a != NULL)
	{
		ft_printf("%i\n", tmp_a->content);
		tmp_a = tmp_a->next;
	}
	ft_printf("stack_b\n");
	tmp_b = stack_b;
	while (tmp_b != NULL)
	{
		ft_printf("%i\n", tmp_b->content);
		tmp_b = tmp_b->next;
	}
}
