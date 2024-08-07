/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   namespace.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:05:58 by mgirardo          #+#    #+#             */
/*   Updated: 2023/05/04 16:51:59 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	gl_var = 1;
int	f(void){return 2;}

namespace	Foo
{
	int	gl_var = 3;
	int f(void){return 4;}
}

namespace	Bar
{
	int	gl_var = 5;
	int	f(void){return 6;}
}

namespace	Muf = Bar;

int	main(void)
{
	printf("gl_var :	[%d]\n", gl_var);
	printf("f() :		[%d]\n\n", f());

	printf("Foo::gl_var :	[%d]\n", Foo::gl_var);
	printf("Foo::f() :	[%d]\n\n", Foo::f());

	printf("Bar::gl_var :	[%d]\n", Bar::gl_var);
	printf("Bar::f() :	[%d]\n\n", Bar::f());

	printf("Muf::gl_var :	[%d]\n", Muf::gl_var);
	printf("Muf::f() :	[%d]\n\n", Muf::f());

	printf("::gl_var :	[%d]\n", ::gl_var);
	printf("::f() :		[%d]\n\n", ::f());

	/*	premiere et derniere ligne execute la meme chose, derniere utiliser
		lorsau'il y a plusieurs namespace
		<namespace_vide>::gl_var*/

	return 0;
}
