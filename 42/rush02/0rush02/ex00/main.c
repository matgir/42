/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 16:38:28 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/22 15:33:46 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int				ft_chek_arg(char *str);
unsigned int	ft_clean_before_nd_nb_paquets(char *str);
char			*ft_strcpy(char *str);
char			**split(char *str);

int ft_lenstr(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int ac, char **av)
{
	unsigned int	j;
	char			*str;
	char			*strcpy;
	unsigned int	i;
	char			**tab;

	(void) ac;
	str = av[1];
	if (ft_chek_arg(str) != 0)
	{
		write (1, "Error\n", 6);
		return (0);
	}
	j = ft_clean_before_nd_nb_paquets(str);
	i = ft_lenstr(str);
	strcpy = 0;
	if (i % 3 == 0)
	{
		(void) strcpy;
		tab = split(str);
	}
	else
	{
		strcpy = ft_strcpy(str);
		tab = split(strcpy);
		i = ft_lenstr(strcpy);
	}
	printf("%s\n", str);
	printf("%d\n", j);
	printf("%s\n", strcpy);
	(void) tab;
	int m = i / 3;
	int x = 0;
	int y = 0;
	while (x < m)
	{
		while (y < 3)
		{
			write (1, &tab[x][y], 1);
			if (y < 3)
			{
				write (1, " ", 1);
			}
			y++;
		}
		x++;
		y = 0;
		write(1, "\n", 1);
	}
	return (0);
}
