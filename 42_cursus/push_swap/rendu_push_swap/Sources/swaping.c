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

t_pair	*ft_pair_lstnew(int c_a, int c_b, int m_a, int m_b)
{
	t_pair	*new;

	new = malloc(sizeof(t_pair));
	if (new == NULL)
		return (NULL);
	new->content_a = c_a;
	new->content_b = c_b;
	new->nb_moves_a = m_a;
	new->nb_moves_b = m_b;
	new->tt_nb_moves = 0;
	new->nb_rb = 0;
	new->nb_ra = 0;
	new->nb_rr = 0;
	new->nb_rra = 0;
	new->nb_rrb = 0;
	new->nb_rrr = 0;
	new->next = NULL;
	return (new);
}

int	nb_move(t_ps_list *stack, int value)
{
	if (place(stack, value) <= stack_size(stack) / 2)
		return (place(stack, value));
	else
		return (-(stack_size(stack) - place(stack, value)));
}

void	ft_pair_lstadd_back(t_pair **alst, t_pair *new)
{
	t_pair	*ptr;

	if (*alst == NULL)
		*alst = new;
	else
	{
		ptr = *alst;
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
	}
}

void	ft_pair_lstclear(t_pair **lst)
{
	t_pair	*ptr;
	t_pair	*next;

	ptr = *lst;
	while (ptr != NULL)
	{
		next = ptr->next;
		free(ptr);
		ptr = next;
	}
	*lst = NULL;
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
