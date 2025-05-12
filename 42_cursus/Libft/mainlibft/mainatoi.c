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

int	ft_ps_atoi(char *nptr, int *error);

int	main(int ac, char** av)
{
	int error = 0;
	(void)ac;
	printf("%d\n", atoi(av[1]));
	printf("%d\n%d\n", ft_ps_atoi(av[1], &error), error);
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


