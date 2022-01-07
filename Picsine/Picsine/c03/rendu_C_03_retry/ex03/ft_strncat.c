/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 22:23:46 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/19 10:09:45 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	ldest;
	unsigned int	i;

	ldest = 0;
	while (dest[ldest])
		ldest++;
	i = 0;
	while (i < nb && src[i])
	{
		dest[ldest] = src[i];
		ldest++;
		i++;
	}
	dest[ldest] = '\0';
	return (dest);
}
