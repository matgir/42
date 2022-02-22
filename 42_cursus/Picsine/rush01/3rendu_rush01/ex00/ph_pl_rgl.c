/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_pl_rgl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 17:14:14 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/15 17:23:35 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	rg(char *str, int i, int c1, int c2)
{
	int	c3;
	int	c4;
	int	c;

	c3 = 0;
	c4 = 0;
	c = i + 8;
	while (i < c)
	{
		if (str[i] == '1')
			c1++;
		if (str[i] == '2')
			c2++;
		if (str[i] == '3')
			c3++;
		if (str[i] == '4')
			c4++;
		i += 2;
	}
	if (c1 != 1 || c4 > 1 || c3 > 2
		|| (c3 == 2 && c4 == 1) || (c2 == 3 && c1 != 1))
		return (1);
	return (0);
}

int	rgl(char *str)
{
	int	i;
	int	c1;
	int	c2;

	i = 0;
	c1 = 0;
	c2 = 0;
	if (rg(str, i, c1, c2) == 1)
		return (1);
	else if (rg(str, i + 8, c1, c2) == 1)
		return (1);
	else if (rg(str, i + 16, c1, c2) == 1)
		return (1);
	else if (rg(str, i + 24, c1, c2) == 1)
		return (1);
	return (0);
}

int	pl(char *str)
{
	unsigned int	i;

	i = 16;
	while (i < 24)
	{
		if (str[i] == '1' && str[i + 8] == '1')
			return (1);
		if (str[i] == '2' && str[i + 8] == '4')
			return (1);
		if (str[i] == '3' && (str[i + 8] == '3' || str[i + 8] == '4'))
			return (1);
		if (str[i] == '4' && str[i + 8] != '1')
			return (1);
		i += 2;
	}
	return (0);
}

int	ph(char *str)
{
	unsigned int	i;

	i = 0;
	while (i < 8)
	{
		if (str[i] == '1' && str[i + 8] == '1')
			return (1);
		if (str[i] == '2' && str[i + 8] == '4')
			return (1);
		if (str[i] == '3' && (str[i + 8] == '3' || str[i + 8] == '4'))
			return (1);
		if (str[i] == '4' && str[i + 8] != '1')
			return (1);
		i += 2;
	}
	return (0);
}
