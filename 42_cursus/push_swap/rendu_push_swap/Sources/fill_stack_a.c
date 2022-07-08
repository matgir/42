/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 17:40:08 by mgirardo          #+#    #+#             */
/*   Updated: 2022/07/05 17:40:10 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

t_ps_list	*fill_stack_a(char **av)
{
	t_ps_list	*stack_a;
	t_ps_list	*tmp_lst;
	int			i;
	int			tmp;

	i = 0;
	stack_a = NULL;
	while (av[++i])
	{
		tmp = ft_atoi(av[i]);
		tmp_lst = ft_ps_lstnew(tmp);
		if (tmp_lst == NULL)
		{
			ft_ps_lstclear(&stack_a); //check if it really works
			ft_putendl_fd("Error alloc", 2);
			return (NULL);
		}
		ft_ps_lstadd_back(&stack_a, tmp_lst);
	}
	return (stack_a);
}
