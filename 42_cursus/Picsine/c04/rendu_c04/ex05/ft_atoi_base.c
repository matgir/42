/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 19:46:14 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/19 11:40:39 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	not_good(char *base)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (base[i])
	{
		if (base[i] < '!' || base[i] == '+' || base[i] == '-'
			|| base[i] > '~' || base[i] == '\t' || base[i] == '\n'
			|| base[i] == '\v' || base[i] == '\f' || base[i] == '\r')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	l(char *base)
{
	unsigned int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	ft_verif_base(char *base)
{
	if (l(base) < 2)
		return (1);
	if (not_good(base) == 0)
		return (1);
	return (0);
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

int	ft_atoi_base(char *str, char *base)
{
	int				nb;
	char			sgn;
	unsigned int	i;

	nb = 0;
	sgn = 1;
	i = 0;
	if (ft_verif_base(base) == 1)
		return (0);
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
		nb = nb * (l(base)) + (ft_nb_inbase(str[i], base));
		i++;
	}
	return (nb * sgn);
}
