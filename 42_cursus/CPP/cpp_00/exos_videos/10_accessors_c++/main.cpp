/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:56:04 by mgirardo          #+#    #+#             */
/*   Updated: 2023/05/04 16:56:05 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "sample_class.hpp"

int	main(void)
{
	Sample	instance;

	instance.setfoo(42);
	std::cout << "instance.getfoo(): " << instance.getfoo() << std::endl;
	instance.setfoo(-42);
	std::cout << "instance.getfoo(): " << instance.getfoo() << std::endl;

	return(0);
}
