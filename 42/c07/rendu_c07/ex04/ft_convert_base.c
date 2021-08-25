/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 18:49:25 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/25 19:00:59 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ck(char *baz);
int	l(char *baz);
int	ft_nb_inbase(char str, char *base);
int	ft_atoi_base(char *str, char *base, int lbaz);

char	*ft_putnbr_base(int nbr, char *base, int lbaz)
{
	long int	nb;
	int			i;
	char		*str;

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
	while (i <= (ac / 2 - 1))
	{
		str = av[i];
		av[i] = av[ac - i - 1];
		av[ac - i - 1] = str;
		i++;
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		i;
	char	*str;

	if (ck(base_from) || ck(base_to) || l(base_from) < 2 || l(base_to) < 2)
		return (0);
	i = ft_atoi_base(nbr, base_from, l(base_from));
	str = ft_putnbr_base(i, base_to, l(base_to));
	ft_rev_tab(l(str), str);
	return (str);
}
