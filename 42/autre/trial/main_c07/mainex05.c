/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainex05.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 19:37:58 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/26 15:45:54 by mgirardo         ###   ########.fr       */
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
	(void) av;
	tab = ft_split("en voila une belle maison toute rouge", " e");
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
