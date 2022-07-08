/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:26:46 by mgirardo          #+#    #+#             */
/*   Updated: 2022/07/05 11:26:58 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

int	main(int ac, char **av)
{
	t_ps_list	*stack_a;

	if (ft_ps_parsing(ac, av) == 0)
		return (0);
	stack_a = fill_stack_a(av);
	if (stack_a == NULL)
		return (0);
	if (swaping(&stack_a) == 0)
		ft_ps_lstclear(&stack_a);
	return (1);
}
