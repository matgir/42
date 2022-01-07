/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 21:24:42 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/19 10:06:10 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	ldest;
	unsigned int	i;

	ldest = 0;
	while (dest[ldest])
		ldest++;
	i = 0;
	while (src[i])
	{
		dest[ldest] = src[i];
		ldest++;
		i++;
	}
	dest[ldest] = '\0';
	return (dest);
}
