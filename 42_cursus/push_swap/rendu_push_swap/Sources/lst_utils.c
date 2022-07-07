/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:21:46 by mgirardo          #+#    #+#             */
/*   Updated: 2022/07/07 18:21:49 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

t_ps_list	*ft_ps_lstlast(t_ps_list *stack)
{
	while (stack != NULL && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

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