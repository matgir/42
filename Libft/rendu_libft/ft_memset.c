/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:44:37 by mgirardo          #+#    #+#             */
/*   Updated: 2021/12/13 14:15:23 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stddef.h>

/*void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*dooble;

	i = 0;
	dooble = s;
	while (i <= n)
	{
		dooble[i] = (unsigned char) c;
		i++;
		//dooble++;
	}
	return (s);
}


void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*dooble;

	i = -1;
	dooble = s;
	while (++i <= n)
		dooble[i] = (unsigned char) c;
	return (s);
}*/

/*void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*dooble;

	dooble = s;
	while (n-- != 0)
		*dooble++ = (unsigned char) c;
	return (s);
}*/

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	
	i = 0;
	while (n != 0)
	{
		((unsigned char *)s)[i] = (unsigned char) c;
		n--;
		i++;
	}

	return (s);
}
