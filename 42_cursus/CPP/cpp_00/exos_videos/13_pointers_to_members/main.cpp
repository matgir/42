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
	// Sample	instance2;
	Sample	*instancep = &instance;

	int		Sample::*p = NULL;
	// ici declaration d'un pointeur *p (initialise a NULL)
	// 	sur un int de la classe Sample
	void	(Sample::*f)(void)const;

	p = &Sample::foo;
	// assignation de ladresse du membre foo au pointeur *p

	std::cout << "Value of member foo in instance = " << instance.foo << std::endl;
	// std::cout << "Value of member foo in instance2 = " << instance2.foo << std::endl;
	instance.*p = 21;
	std::cout << "Value of member foo in instance = " << instance.foo << std::endl;
	instancep->*p = 42;
	// instance2.*p = 42;
	std::cout << "Value of member foo in instance = " << instance.foo << std::endl;
	// std::cout << "Value of member foo in instance2 = " << instance2.foo << std::endl;

	f = &Sample::bar;

	(instance.*f)();
	(instancep->*f)();

	return (0);
}
