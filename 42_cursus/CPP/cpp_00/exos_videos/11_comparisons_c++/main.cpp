/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:13:28 by mgirardo          #+#    #+#             */
/*   Updated: 2023/05/04 19:13:29 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "sample_class.hpp"

int	main(void)
{
	Sample	instance1(42);
	Sample	instance2(42);


	// if (&instance1 == &instance1)
	// 	std::cout << "instance1 and instance1 are physically equal" << std::endl;
	// else
	// 	std::cout << "instance1 and instance1 are not physically equal" << std::endl;

	if (&instance1 == &instance2)
		std::cout << "instance1 and instance2 are physically equal" << std::endl;
	else
		std::cout << "instance1 and instance2 are not physically equal" << std::endl;


	if (instance1.compare(&instance1) == 0)
		std::cout << "instance1 and instance1 are structuraly equal" << std::endl;
	else
		std::cout << "instance1 and instance1 are not structuraly equal" << std::endl;

	if (instance1.compare(&instance2) == 0)
		std::cout << "instance1 and instance2 are structuraly equal" << std::endl;
	else
		std::cout << "instance1 and instance2 are not structuraly equal" << std::endl;

	return (0);
}
