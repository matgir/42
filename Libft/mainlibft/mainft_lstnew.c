/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainft_lstnew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 15:36:24 by mgirardo          #+#    #+#             */
/*   Updated: 2021/12/21 15:42:49 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

t_list	*ft_lstnew(void *content);

int		main(int ac, char **av)
{
	(void) ac;

	printf("%p\n", (ft_lstnew(av[1])->content));
	return (0);
}
