/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainmemtruc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:47:12 by mgirardo          #+#    #+#             */
/*   Updated: 2021/11/24 12:00:08 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stddef.h>
#include<stdio.h>
#include<string.h>

/*int	main(void)
  {
  void	*s;
  int	c;
  size_t	n;

  c = 5;
  n = 2;
  s = &s;
  printf("%p\n", s);
  memset(s, c, n);
  printf("%p", s);
  return (0);
  }*/

void printArray(int arr[], int n)
{	
	for (int i=0; i<n; i++)
		printf("%d ", arr[i]);
}

/*int main()
  {

  int n = 10;
  int arr[n];

// Fill whole array with 0.
memset(arr, 0, n*sizeof(arr[0]));
printf("Array after memset()\n");
printArray(arr, n);

return (0);
}*/

/*int main()
  {

  int n = 10;
  int arr[n];

// Fill whole array with 100.
memset(arr, 5, n*sizeof(arr[0]));
printf("Array after memset()\n");
printArray(arr, n);

return (0);
}*/

int	main()
{
	char 	str[50];
	int	c = 10;

	strcpy(str, "this is string.h library function");
	puts(str);

	memset(str, c, 7);
	puts(str);

	return (0);
}
