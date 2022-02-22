/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainex07.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 21:51:19 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/10 11:12:53 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int	*tab, int	size);

int main(void)
{
	/*int	tab[6] = {1, 2, 3, 4, 5, 6};
	  int	size;
	  int	i;

	  i = 0;
	  size = 6;
	  ft_rev_int_tab(tab, size);
	  while(i <= size)
	  {
	  printf("%d", tab[i]);
	  i++;
	  }
	  return (0);*/

	int        tab[9] = {-4, -3, -2, -1, 0, 1, 2, 3, 4};
	int        size;

	size = 9;
	//printf("test");
	ft_rev_int_tab(tab, size);
	//printf("test");
	for(size = 0; size < 9; size++)
		printf("%d ", tab[size]);
}
