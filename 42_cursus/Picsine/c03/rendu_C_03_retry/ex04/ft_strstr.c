/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 09:35:43 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/19 10:15:15 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	len(char *to_find)
{
	unsigned int	i;

	i = 0;
	while (to_find[i])
		i++;
	return (i);
}

char	*verif(char *str, char *to_find, unsigned int i, unsigned int j)
{
	unsigned int	l;

	while (str[i])
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			l = i;
			while (l <= (i + len(to_find)) && (str[l] || to_find[j]))
			{
				if (str[l] == to_find[j])
				{
					l++;
					j++;
					if (j == len(to_find))
						return (&str[l - j]);
				}
				else
					break ;
			}
		}
		i++;
	}
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (len(to_find) == 0)
		return (str);
	return (verif(str, to_find, i, j));
}
