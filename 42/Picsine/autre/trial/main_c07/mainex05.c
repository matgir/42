/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainex05.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 19:37:58 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/26 16:08:49 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	**ft_split(char *str, char *charset);

int	main(int ac, char **av)
{
	char	**tab;
	unsigned int	i;
	unsigned int	j;

	(void) ac;
//	(void) av;
//	tab = ft_split("en voila une belle maison toute rouge", " e");
	tab = ft_split(av[1], av[2]);
	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			write (1, &tab[i][j], 1);
			j++;
		}
		write (1, "\n", 1);
		i++;
	}
	return (0);
}
