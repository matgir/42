/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainmemset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:47:12 by mgirardo          #+#    #+#             */
/*   Updated: 2021/11/25 16:27:53 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stddef.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void	*ft_memset(void *s, int c, size_t n);

int	main(void)
{
	char	s[] = "bonjour a vous";
	char	l[] = "bonjour a vous";
	int	c;
	size_t	n;
	
	c = 65;
	n = 8;
	printf("%s\n", s);
	ft_memset(s, c, n);
	printf("%s\n", s);
	
	c = 65;
	n = 8;
	printf("%s\n", l);
	memset(l, c, n);
	printf("%s\n", l);
	
	return (0);
}


/*
void	printArray(char arr[], int n)
{	
	for (int i = 0; i < n; i++)
		printf("%c ", arr[i]);
}



int	main()
{
	int n = 10;
	int arr[n];

	// Fill whole array with 0.
	memset(arr, 0, n*sizeof(arr[0]));
	printf("Array after memset()\n");
	printArray(arr, n);

	return (0);
}



int	main()
{
	int n = 10;
	char *arr = malloc(n);

	// Fill whole array with 100.
	memset(arr, '8', n);
	printf("Array after memset()\n");
	printArray(arr, n);

	return (0);
}



int	main()
{
	char 	str[50];
	int	c = 48;

	strcpy(str, "this is string.h library function");
	puts(str);

	ft_memset(str, c, 7);
	puts(str);

	return (0);
}



int	main()
{
	int	array[] = { 54, 85, 20, 63, 21};
	size_t	size = sizeof(int)*5;
	int	lengh;
	void	*a;

	a = &array;
	printf("%p\n", a);
	for(lengh = 0; lengh < 5; lengh++)
		printf("%d\n", array[lengh]);
	printf("%p\n", ft_memset(array, 0, size));
	for(lengh = 0; lengh < 5; lengh++)
		printf("%d\n", array[lengh]);
	printf("%p\n", a);
	return (0);
}*/
