/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:14:20 by mgirardo          #+#    #+#             */
/*   Updated: 2023/05/04 19:14:20 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "sample_class.hpp"

int	main(void)
{
	Sample	instance;
	Sample	*instancep = &instance;

	int		Sample::*p = NULL;
	void	(Sample::*f)(void)const;

	p = &Sample::foo;

	std::cout << "Value of member foo = " << instance.foo << std::endl;
	instance.*p = 21;
	std::cout << "Value of member foo = " << instance.foo << std::endl;
	instance.*p = 42;
	std::cout << "Value of member foo = " << instance.foo << std::endl;

	f = &Sample::bar;

	(instance.*f)();
	(instancep->*f)();

	return (0);
}
