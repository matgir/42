/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:24:08 by itahani           #+#    #+#             */
/*   Updated: 2021/12/01 11:13:12 by itahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned int	i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		*(char *)(dst + i) = *(const char *)(src + i);
		i++;
	}
	return (dst);
}

/*void	*ft_memcpy(void *dst, const void *src, size_t n)
  {
  unsigned long int	i;
  unsigned char		*d;
  unsigned char		*s;

  i = 0;
  s = (unsigned char *)src;
  d = (unsigned char *)dst;
  if (dst == NULL && src == NULL)
  {
  return (NULL);
  }
  while (i < n)
  {
 *d = *s;
 d++;
 s++;
 i++;
 }
 return (dst);
 }*/

/*#include <stdio.h>
  int main()
  {
  int src = 42;
  int dst = -1;
  printf("%d\n", *(int *)ft_memcpy(&dst, &src, sizeof(int)));
  printf("%d\n", *(int *) memcpy(&dst, &src, sizeof(int)));
//suite pour test memmove	
char s[] = "Bonjour                               ";

char *d;

d = s + 3;
memcpy(d, s, 20);
printf("%s\n", s);

char smove[] = "Bonjour                               ";
char *dmove = s + 3;
memmove(d, smove, 20);
printf("%s\n", s);

return(0);
}*/
