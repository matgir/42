/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azheng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 16:33:47 by azheng            #+#    #+#             */
/*   Updated: 2021/08/22 10:58:52 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

char	**split(char *str)
{
	char	**tab;
	int		i;
	int		l;

	i = -1;
	l = -1;
	tab = malloc(sizeof(tab) * (ft_strlen(str) / 3 + 1));
	if (!tab)
		return (0);
	while (++i <= ft_strlen(str) / 3)
	{
		tab[i] = malloc (sizeof(char) * 4);
		if (!tab[i])
			return (0);
	}
	i = -1;
	while (str[++i])
	{
		tab[i / 3][i % 3] = str[i];
		if (i % 3 == 2)
			tab[i / 3][3] = '\0';
	}
	tab[ft_strlen(str) / 3] = NULL;
	return (tab);
}

/*int main()
{
	char *a = "002144129685006125";
	char **tab = split(a);
	(void) tab;
	int m = ft_strlen(a) / 3;
	int i = 0;
	int j = 0;
	while (i < m)
	{
		while (j < m)
		{
			write (1, &tab[i][j], 1);
			if (j < 3)
			{
				write (1, " ", 1);
			}
			j++;
		}
		i++;
		j = 0;
		write(1, "\n", 1);
	}
}*/
