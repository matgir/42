/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainex08.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 09:44:14 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/10 11:13:57 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int	*tab, int	size);

int	main(void)
{
	int        tab[13] = {45932, 54, -45387,2147483647, -8596, -2147483648, 0, 43785, -857, -273856, 783, -28614795, 825};
	int        size;

	size = 13;
	//printf("test");
	ft_sort_int_tab(tab, size);
	//printf("test");
	for(size = 0; size < 13; size++)
		printf("%d ", tab[size]);
	return (0);
}
