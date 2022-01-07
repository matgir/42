/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 16:49:02 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/26 17:45:27 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int start, int end);

int	main(int ac, char **av)
{
	int	i;
	int	*tab;
	//int	start;
	//int	end;

	i = 0;
	//start = 12;
	//end = 12;
	(void) ac;
	//(void) av;
	tab = ft_range(atoi(av[1]), atoi(av[2]));
	//tab = ft_range(start, end);
	if (tab == 0)
		return (0);
	if (atoi(av[1]) > atoi(av[2]))
	//if (start > end)
	{
		while (i <= (atoi(av[1]) - atoi(av[2])))
		//while (i <= (start - end))
		{
			printf("%d\n", tab[i]);
			i++;
		}
	}
	else
	{
		while (i <= (atoi(av[2]) - atoi(av[1])))
		//while (i <= (end - start))
		{
			printf("%d\n", tab[i]);
			i++;
		}
	}
	return (0);
}
