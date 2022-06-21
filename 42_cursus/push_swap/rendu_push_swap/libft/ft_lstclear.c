/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:55:26 by mgirardo          #+#    #+#             */
/*   Updated: 2022/01/04 15:14:49 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;
	t_list	*next;

	ptr = *lst;
	while (ptr != NULL)
	{
		next = ptr->next;
		del(ptr->content);
		free(ptr);
		ptr = next;
	}
	*lst = NULL;
}

/*		- ptr permet de sauvegarder lst pour le mettre a NULL par la suite
 *		- next permet de sauvegarder ptr->next qui sera effcer par la suite
 *		donc irrecuperable sans next		*/
