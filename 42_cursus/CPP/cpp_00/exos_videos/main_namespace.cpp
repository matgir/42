/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   namespace.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:05:58 by mgirardo          #+#    #+#             */
/*   Updated: 2023/03/20 18:06:00 by mgirardo         ###   ########.fr       */
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

}