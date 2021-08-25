/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 19:11:51 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/25 12:20:02 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ck(char *baz)
{
	unsigned int    i;
	unsigned int    j;

	i = 0;
	j = 0;
	while (baz[i])
	{
		if (baz[i] < '!' || baz[i] == '+' || baz[i] == '-' || baz[i] > '~')
			return (1);
		j = i + 1;
		while (baz[j])
		{
			if (baz[i] == baz[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int l(char *baz)
{
	unsigned int	i;

	i = 0;
	while (baz[i])
		i++;
	return (i);
}

int	ft_nb_inbase(char str, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (str == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int ft_atoi_base(char *str, char *base, int lbaz)
{
	int             nb;
	char            sgn;
	unsigned int    i;

	nb = 0;
	sgn = 1;
	i = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == ' ')
		i++;
	while (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sgn *= -1;
		i++;
	}
	while (ft_nb_inbase(str[i], base) != -1)
	{
		nb = nb * (lbaz) + (ft_nb_inbase(str[i], base));
		i++;
	}
	return (nb * sgn);
}

#include <stdlib.h>

char	*ft_putnbr_base(int nbr, char *base, int lbaz)
{
	long int        nb;
	int 			i;
	char *str;

	str = malloc(sizeof(*str) * 34);
	nb = nbr;
	i = 0;
	if (nb < 0)
		nb = nb * -1;
	while (nb > lbaz - 1)
	{
		str[i] = base[nb % lbaz];
		nb = nb / lbaz;
		i++;
	}
	str[i] = base[nb % lbaz];
	i++;
	if (nbr < 0)
	{
		str[i] = '-';
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_rev_tab(int ac, char *av)
{
	int		i;
	char	str;

	i = 0;
	while (i <= (ac / 2))
	{
		str = av[i];
		av[i] = av[ac - i - 1];
		av[ac - i - 1] = str;
		i++;
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	i;
	char *str;

	if (ck(base_from) || ck(base_to) || l(base_from) < 2|| l(base_to) < 2)
		return(0);
	i = ft_atoi_base(nbr, base_from, l(base_from));
	str = ft_putnbr_base(i, base_to, l(base_to));
	ft_rev_tab(l(str), str);
	return (str);

}
