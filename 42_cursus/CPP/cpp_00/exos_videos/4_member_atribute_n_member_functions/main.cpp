/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:52:52 by mgirardo          #+#    #+#             */
/*   Updated: 2023/05/04 16:52:54 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "sample_class.hpp"

int	main()
{
	Sample	instance;

	instance.foo = 42;
	std::cout << "instance.foo = " << instance.foo << std::endl;

	instance.bar();
	
	instance.foo++;
	std::cout << "instance.foo = " << instance.foo << std::endl;
	
	return 0;
}
