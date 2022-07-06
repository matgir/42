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

void	swaping(t_ps_list *stack_a)
{
	t_ps_list	*stack_b;

	stack_b = NULL;
	push_b(&stack_a, &stack_b);
	push_b(&stack_a, &stack_b);
	push_b(&stack_a, &stack_b);
	
	print_stack(stack_a, "\nstack_a");
	print_stack(stack_b, "\nstack_b");

	double_swap(&stack_a, &stack_b);

	print_stack(stack_a, "\nstack_a");
	print_stack(stack_b, "\nstack_b");

	double_rotate(&stack_a, &stack_b);

	print_stack(stack_a, "\nstack_a");
	print_stack(stack_b, "\nstack_b");

	double_reverse_rotate(&stack_a, &stack_b);

	print_stack(stack_a, "\nstack_a");
	print_stack(stack_b, "\nstack_b");

}
