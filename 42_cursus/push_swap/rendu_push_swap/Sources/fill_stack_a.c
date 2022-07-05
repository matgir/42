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

void	ft_ps_lstclear(t_ps_list **lst)
{
	t_ps_list	*ptr;
	t_ps_list	*next;

	ptr = *lst;
	while (ptr != NULL)
	{
		next = ptr->next;
		free(ptr);
		ptr = next;
	}
	*lst = NULL;
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
			ft_ps_lstclear(&stack_a); //check if it really works
			ft_putendl_fd("Error alloc", 2);
			return (NULL);
		}
		ft_ps_lstadd_back(&stack_a, tmp_lst);
	}
	return (stack_a);
}
