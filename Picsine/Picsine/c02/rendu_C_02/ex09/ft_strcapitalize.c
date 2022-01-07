/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 12:07:27 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/11 15:00:03 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	i = 0;
	if (str[i] >= 'a' && str[i] <= 'z')
		str[i] -= 32;
	while (str[i])
	{
		if ((str[i] < '0' || (str[i] > '9' && str[i] < 'A')
				|| (str[i] > 'Z' && str[i] < 'a') || str[i] > 'z'))
		{
			if (str[i + 1] >= 'a' && str[i + 1] <= 'z')
				str[(i + 1)] -= 32;
		}
		i++;
	}
	return (str);
}
