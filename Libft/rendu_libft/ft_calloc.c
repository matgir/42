/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:10:42 by mgirardo          #+#    #+#             */
/*   Updated: 2021/12/13 12:26:02 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	nmemb;
	size_t	size;
	void	**tab;

	nmemb = 5;
	size = 4;
	tab = malloc(nmemb);
	while (nmemb != 0)
	{
		tab[nmemb - 1] = malloc(size);
		tab[nmemb - 1] = 0;
		nmemb--;
	}
	return (tab[nmemb])
}
