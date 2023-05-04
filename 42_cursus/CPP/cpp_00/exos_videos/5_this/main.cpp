/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:53:17 by mgirardo          #+#    #+#             */
/*   Updated: 2023/05/04 16:53:18 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "sample_class.hpp"

int	main(void)
{
	Sample	instance;

	instance.foo++;
	std::cout << "instance.foo = " << instance.foo << std::endl;

	std::cout << "Choose de value of instance.foo : ";
	std::cin >> instance.foo;
	std::cout << "The new value of instance.foo = " << instance.foo << std::endl;

	instance.bar();

	return 0;
}
