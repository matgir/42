/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:41:19 by mgirardo          #+#    #+#             */
/*   Updated: 2022/07/06 15:41:22 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

void	print_stack(t_ps_list	*stack, char *name)
{
	ft_printf("%s\n", name);
	while (stack != NULL)
	{
		ft_printf("%i\n", stack->content);
		stack = stack->next;
	}
}
