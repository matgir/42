/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:25:36 by mgirardo          #+#    #+#             */
/*   Updated: 2022/07/07 18:25:39 by mgirardo         ###   ########.fr       */
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

int	place(t_ps_list *stack, int value)
{
	int	index;

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

int	is_it_good(t_ps_list **stack)
{
	t_ps_list	*tmp;

	tmp = *stack;
	while (tmp->next != NULL)
	{
		if (tmp->content > tmp->next->content)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	fill_pos(t_pair **pair)
{
	(*pair)->tt_nb_moves = taller((*pair)->nb_moves_a, (*pair)->nb_moves_b);
	(*pair)->nb_rr = tiniest((*pair)->nb_moves_a, (*pair)->nb_moves_b);
	if ((*pair)->nb_rr == (*pair)->nb_moves_a)
		(*pair)->nb_rb = (*pair)->tt_nb_moves - (*pair)->nb_rr;
	else
		(*pair)->nb_ra = (*pair)->tt_nb_moves - (*pair)->nb_rr;
}

void	fill_neg(t_pair **pair)
{
	(*pair)->tt_nb_moves = taller((*pair)->nb_moves_a, (*pair)->nb_moves_b);
	(*pair)->nb_rrr = tiniest((*pair)->nb_moves_a, (*pair)->nb_moves_b);
	if ((*pair)->nb_rrr == -(*pair)->nb_moves_a)
		(*pair)->nb_rrb = (*pair)->tt_nb_moves - (*pair)->nb_rrr;
	else
		(*pair)->nb_rra = (*pair)->tt_nb_moves - (*pair)->nb_rrr;
}
