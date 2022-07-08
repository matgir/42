/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:09:53 by mgirardo          #+#    #+#             */
/*   Updated: 2022/07/08 15:09:56 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

int	nb_move(t_ps_list *stack, int value)
{
	if (place(stack, value) <= stack_size(stack) / 2)
		return (place(stack, value));
	else
		return (-(stack_size(stack) - place(stack, value)));
}

int	taller(int i1, int i2)
{
	if (i1 <= 0 && i2 <= 0)
	{
		i1 = i1 * -1;
		i2 = i2 * -1;
	}
	if (i1 > i2)
		return (i1);
	return (i2);
}

int	tiniest(int i1, int i2)
{
	if (i1 <= 0 && i2 <= 0)
	{
		i1 = i1 * -1;
		i2 = i2 * -1;
	}
	if (i1 < i2)
		return (i1);
	return (i2);
}

void	moves(t_pair **info)
{
	t_pair	*pair;

	pair = *info;
	while (pair != NULL)
	{
		if (pair->nb_moves_a >= 0 && pair->nb_moves_b >= 0)
		{
			pair->tt_nb_moves = taller(pair->nb_moves_a, pair->nb_moves_b);
			pair->nb_rr = tiniest(pair->nb_moves_a, pair->nb_moves_b);
			if (pair->nb_rr == pair->nb_moves_a)
				pair->nb_rb = pair->tt_nb_moves - pair->nb_rr;
			else
				pair->nb_ra = pair->tt_nb_moves - pair->nb_rr;
		}
		if (pair->nb_moves_a <= 0 && pair->nb_moves_b <= 0)
		{
			pair->tt_nb_moves = taller(pair->nb_moves_a, pair->nb_moves_b);
			pair->nb_rrr = tiniest(pair->nb_moves_a, pair->nb_moves_b);
			if (pair->nb_rrr == -pair->nb_moves_a)
				pair->nb_rrb = pair->tt_nb_moves - pair->nb_rrr;
			else
				pair->nb_rra = pair->tt_nb_moves - pair->nb_rrr;
		}
		if (pair->nb_moves_a >= 0 && pair->nb_moves_b <= 0)
		{
			pair->tt_nb_moves = pair->nb_moves_a + (pair->nb_moves_b * -1);
			pair->nb_ra = pair->nb_moves_a;
			pair->nb_rrb = pair->nb_moves_b * -1;
		}
		if (pair->nb_moves_a <= 0 && pair->nb_moves_b >= 0)
		{
			pair->tt_nb_moves = pair->nb_moves_b + (pair->nb_moves_a * -1);
			pair->nb_rra = pair->nb_moves_a * -1;
			pair->nb_rb = pair->nb_moves_b;
		}
		pair = pair->next;
	}
}

t_pair	costless_pair(t_pair *pairs)
{
	t_pair	costless_pair;
	int		least_move;

	least_move = 2147483647;
	moves(&pairs);
	while (pairs != NULL)
	{
		if (pairs->tt_nb_moves < least_move)
		{
			least_move = pairs->tt_nb_moves;
			costless_pair = *pairs;
		}
		pairs = pairs->next;
	}
	costless_pair.next = NULL;
	return (costless_pair);
}