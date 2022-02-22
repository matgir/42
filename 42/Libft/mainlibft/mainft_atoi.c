/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainstrtruc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:16:20 by mgirardo          #+#    #+#             */
/*   Updated: 2021/11/23 17:45:51 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<string.h>
#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>

int	ft_atoi(const char *nptr);

int	main(void)
{
	const char	*nptr;

	nptr = "    \f  \t  \v  \n  \r    +-2458rb22reg";
	printf("%d\n", atoi(nptr));
	printf("%d\n", ft_atoi(nptr));
	return (0);
}

/*size_t strlcat(char *dest, const char *src, size_t size);

  int	main(void)
  {
  char	*dest;
  char	*src;
  size_t	size;

  dest = "bonsoir";
  src = "Hello Hello";
  size = 8;

  printf("%s, %s\n", dest, src);
  strlcat(dest, src, size);
  printf("%s, %s\n", dest, src);


  return (0);
  }*/


