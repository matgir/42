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

void	ft_ps_lstadd_back(t_ps_list **alst, t_ps_list *new)
{
	t_ps_list	*ptr;

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

t_ps_list	*ft_ps_lstnew(int content)
{
	t_ps_list	*new;

	new = malloc(sizeof(t_ps_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

t_ps_list	*fill_stack_a(char **av)
{
	t_ps_list	*stack_a;
	t_ps_list	*tmp_lst;
	int		i;
	int		tmp;

	i = 0;
	stack_a = NULL;
	while (av[++i])
	{
		tmp = atoi(av[i]);
		tmp_lst = ft_ps_lstnew(tmp);
		if (tmp_lst == NULL)
		{
			ft_putendl_fd("Error alloc", 2);
			return (NULL); // maybe do a function that free everything
		}
		ft_ps_lstadd_back(&stack_a, tmp_lst);
	}
	return (stack_a);
}

int	main(int ac, char **av)
{
	t_ps_list	*stack_a;
	
	if (ft_ps_parsing(ac, av) == 0)
		return (0);
	stack_a = fill_stack_a(av);
	if (stack_a == NULL)
		return (0);
}
