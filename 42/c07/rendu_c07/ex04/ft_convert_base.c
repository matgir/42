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

char	*ft_putnbr_base(int nbr, char *base, int lbaz)
{
	long int        nb;

	nb = nbr;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * -1;
	}
	if (nb > lbase - 1)
	{
		ft_putnbr_base((nb / lbase), base);
		ft_putnbr_base((nb % lbase), base);
	}
	else
		(ft_putchar(base[nb % lbase]));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	i;

	if (ck(base_from) || ck(base_to) || l(base_from) < 2|| l(base_to) < 2)
		return(0);
	i = ft_atoi_base(nbr, base_from, l(base_from));
	str = ft_putnbr_base(i, base_to, l(base_to))

}
