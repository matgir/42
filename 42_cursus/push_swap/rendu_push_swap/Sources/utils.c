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