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
	return (new);
}

int	nb_move(t_ps_list *stack, int value)
{
	if (place(stack, value) <= stack_size(stack) / 2)
		return (place(stack, value)); // et donc RA
	else
		return (-(stack_size(stack) - place(stack, value))); // et donc RRa
}

void	ft_pair_lstadd_back() // a coder

t_pair	*pair(t_ps_list *stack_a, t_ps_list *stack_b)
{
	t_pair	*pair;
	t_pair	*tmp_pair;
	int		c_a;

	pair = NULL;
	while (stack_b != NULL)
	{
		c_a = smallest_bis(stack_a, stack_b->content);
		tmp_pair = ft_pair_lstnew(c_a, stack_b->content, nb_move(stack_a, c_a), 0);
		if (tmp_pair == NULL)
		{
			ft_pair_lstclear(*tmp_pair); // a coder
			return (NULL);
		}
		ft_pair_lstadd_back(&pair, tmp_pair);
		stack_b = stack_b->next;
	}
}

void	to_move_a_pair(t_ps_list **stack_a, t_ps_list **stack_b)
{
	t_pair	*the_pair;

	the_pair = pair(*stack_a, *stack_b);
	//list chainer des pair, remplir nb move b et choisir meilleur pour executer

}

void	sort(t_ps_list **stack_a, t_ps_list **stack_b)
{
	int	median;

//
	to_the_top(stack_a, smallest(*stack_a), 'a');
//
	median = find_median(*stack_a); //maybe put it directly under
	first_triage(stack_a, stack_b, median);
	while ((*stack_b) != NULL)
	{
		to_move_a_pair(stack_a, stack_b);
		push_a(stack_a, stack_b);
	}
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
