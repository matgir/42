/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 16:48:21 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/26 17:45:29 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_malloc(int start, int end)
{
	int	*tab;
	if (start < end)
		tab = malloc(sizeof(int) * (end - start + 1));
	else
		tab = malloc(sizeof(int) * (start - end + 1));
	return (tab);
}

int	*ft_range(int start, int end)
{
	int				*tab;
	unsigned int	i;

	tab = ft_malloc(start, end);
	i = 0;
	if (start < end)
	{
		while (start <= end)
		{
			tab[i] = start;
			i++;
			start++;
		}
	}
	else
	{
		while (start >= end)
          {
              tab[i] = start;
			  i++;
              start--;
          }
	}
	return (tab);
}
