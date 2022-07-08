/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_pair_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 15:07:09 by mgirardo          #+#    #+#             */
/*   Updated: 2022/07/08 15:07:11 by mgirardo         ###   ########.fr       */
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
	new->tt_nb_moves = 0;
	new->nb_rb = 0;
	new->nb_ra = 0;
	new->nb_rr = 0;
	new->nb_rra = 0;
	new->nb_rrb = 0;
	new->nb_rrr = 0;
	new->next = NULL;
	return (new);
}

void	ft_pair_lstadd_back(t_pair **alst, t_pair *new)
{
	t_pair	*ptr;

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

void	ft_pair_lstclear(t_pair **lst)
{
	t_pair	*ptr;
	t_pair	*next;

	ptr = *lst;
	while (ptr != NULL)
	{
		next = ptr->next;
		free(ptr);
		ptr = next;
	}
	*lst = NULL;
}
