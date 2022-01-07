/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chek_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 16:40:16 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/22 10:58:49 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_chek_arg(char *str)
{
	int				sign;
	unsigned int	i;

	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] > 8 && str[i] < 14))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (sign < 0 || str[i] < '0' || str[i] > '9')
		return (1);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '.' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
		return (1);
	str[i] = '\0';
	return (0);
}

unsigned int	ft_clean_before_nd_nb_paquets(char *str)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	l;

	i = 0;
	l = 0;
	while (str[i] == ' ' || (str[i] > 8 && str[i] < 14)
		|| str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		str[l] = str[i];
		i++;
		l++;
	}
	str[l] = '\0';
	j = 0;
	j = l / 3;
	if (l % 3 > 0)
		j++;
	return (j);
}

char	*ft_cpy1(char *str, unsigned int lstr)
{
	unsigned int	i;
	char			*strcpy;

	i = 0;
	strcpy = malloc(sizeof(char) * (lstr + 3));
	if (strcpy == 0)
		return (0);
	lstr = 0;
	while (i < 2)
	{
		strcpy[i] = '0';
		i++;
	}
	while (str[lstr])
	{
		strcpy[i] = str[lstr];
		i++;
		lstr++;
	}
	strcpy[i] = '\0';
	return (strcpy);
}

char	*ft_cpy2(char *str, unsigned int lstr)
{
	unsigned int	i;
	char			*strcpy;

	i = 0;
	strcpy = malloc(sizeof(char) * (lstr + 2));
	if (strcpy == 0)
		return (0);
	lstr = 0;
	while (i < 1)
	{
		strcpy[i] = '0';
		i++;
	}
	while (str[lstr])
	{
		strcpy[i] = str[lstr];
		i++;
		lstr++;
	}
	strcpy[i] = '\0';
	return (strcpy);
}

char	*ft_strcpy(char *str)
{
	unsigned int	i;
	unsigned int	j;
	char			*strcpy;
	unsigned int	lstr;

	i = 0;
	lstr = 0;
	while (str[lstr])
		lstr++;
	j = lstr % 3;
	if (j == 1)
		strcpy = ft_cpy1(str, lstr);
	if (j == 2)
		strcpy = ft_cpy2(str, lstr);
	return (strcpy);
}
