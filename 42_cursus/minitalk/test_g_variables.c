/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_g_variables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:57:16 by mgirardo          #+#    #+#             */
/*   Updated: 2022/08/02 15:57:18 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
void func_1();
void func_2();
void func_3();
int a, b = 10;  // declaring and initializing global variables

int main()
{
	printf("Global a = %d\n", a);
	printf("Global b = %d\n\n", b);

	func_1();
	printf("Global a after func1 = %d\n", a);

	func_2();
	printf("Global a after func2 = %d\n", a);

	func_3();
	printf("Global a after func3 = %d\n", a);


	// signal to operating system program ran fine
	return 0;
}

void func_1()
{
	printf("From func_1() Global a = %d\n", a);
	printf("From func_1() Global b = %d\n\n", b);
}

void func_2()
{
	int a = 5;
	printf("Inside func_2() a = %d\n\n", a);
}

void func_3()
{
	a = 5;
	printf("Inside func_3() a = %d\n\n", a);
}