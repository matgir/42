/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <itahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:50:15 by itahani           #+#    #+#             */
/*   Updated: 2023/11/12 22:52:31 by itahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_puthexa(unsigned int nbr, int i, char *res)
{
	unsigned long	n;
	static char		hexa[16] = "0123456789abcdef";

	n = nbr;
	if (n >= 16)
		ft_puthexa((n / 16), i - 1, res);
	res[i] = hexa[n % 16];
}

char	*get_hexa_color(char *color)
{
	int		i;
	int		nb;
	char	*res;

	i = 1;
	nb = ft_atoi(color);
	free(color);
	res = malloc(sizeof(char) * 3);
	res[0] = '0';
	res[1] = '0';
	ft_puthexa(nb, i, res);
	res[2] = '\0';
	return (res);
}

int	hexa_char_to_int(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	return (-1);
}

void	ft_strjoin_hexa(char *res, t_color *color)
{
	char	*tmp;

	res[0] = '0';
	res[1] = 'x';
	res[2] = '\0';
	tmp = ft_strjoin(res, color->r_hexa);
	free(res);
	res = malloc(sizeof(char) * 9);
	res = ft_strjoin(tmp, color->g_hexa);
	free(tmp);
	tmp = ft_strdup(res);
	free(res);
	color->hexa = ft_strjoin(tmp, color->b_hexa);
	free(tmp);
}

void	get_color(char *rgb, char *color, int *i)
{
	int	j;

	j = 0;
	while (rgb[*i] && rgb[*i] >= '0' && rgb[*i] <= '9')
	{
		color[j] = rgb[*i];
		*i += 1;
		j++;
	}
	color[j] = '\0';
}
