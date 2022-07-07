/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 11:25:16 by mgirardo          #+#    #+#             */
/*   Updated: 2022/07/07 11:25:19 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

void	sort_three(t_ps_list **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->content;
	second = (*stack)->next->content;
	third = (*stack)->next->next->content;
	if (first < second && first < third)
	{
		reverse_a(stack);
		swap_a(stack);
	}
	if (first > second && first < third)
		swap_a(stack);
	if (first < second && first > third)
		reverse_a(stack);
	if (first > second && second > third && first > third)
	{
		rotate_a(stack);
		swap_a(stack);
	}
	if (first > second && first > third && second < third)
		rotate_a(stack);
}