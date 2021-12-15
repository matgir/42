/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:36:57 by mgirardo          #+#    #+#             */
/*   Updated: 2021/12/15 11:54:27 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

/*static char	*verif(const char *big, const char *little, size_t i, size_t len)
  {
  size_t	l;
  size_t	j;
  size_t	lenlittle;

  lenlittle = ft_strlen(little);
  while (i < len && big[i])
  {
  j = 0;
  if (big[i] == little[j])
  {
  l = i;
  while (l < (i + lenlittle) && (big[l] && little[j]) && l < len)
  {
  if (big[l] == little[j])
  {
  if (j == lenlittle - 1)
  return ((char *)&big[l - j]);
  l++;
  j++;
  }
  else
  break ;
  }
  }
  i++;
  }
  return (0);
  }

  char	*ft_strnstr(const char *big, const char *little, size_t len)
  {
  size_t	i;

  i = 0;
  if (ft_strlen(little) == 0)
  return ((char *)big);
  return (verif (big, little, i, len));
  }*/

static char	*verif(const char *big, const char *little, size_t i, size_t len)
{
	size_t	j;
	size_t	lenlittle;

	lenlittle = ft_strlen(little);
	while (i < len && big[i])
	{
		j = 0;
		while (big[i] == little[j] && i < len)
		{
			if (j == lenlittle - 1)
				return ((char *)&big[i - j]);
			i++;
			j++;
		}
	}
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	i = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	return (verif (big, little, i, len));
}
