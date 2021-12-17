/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainft_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 09:46:55 by mgirardo          #+#    #+#             */
/*   Updated: 2021/12/17 14:18:22 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char	**ft_split(char const *s, char c);

int	main(void)
{
	char **tab	;
	unsigned int i;
	unsigned int j;
	//unsigned int count;
	//char str[] = " a b c d e f g h i j k l m n o p q r s t u v w x y z ";

	//printf("%s\n", str);
	tab = ft_split("          ", ' ');
	i = 0;
	//count = 0;
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
	//	count++;
	}
	//printf("%d\n", count);
	tab = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
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
	tab = ft_split("   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ');
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
	tab = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'i');
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
	tab = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'z');
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
	tab = ft_split("", 'z');
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

