/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:54:52 by mgirardo          #+#    #+#             */
/*   Updated: 2023/05/04 16:54:52 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "sample_class.hpp"

int	main(void)
{
	Sample	instance;

	instance.publicfoo = 42;
	std::cout << "instance.publicfoo = " << instance.publicfoo << std::endl;
	// instance._privatefoo = 42;
	// std::cout << "instance._privatefoo = " << instance._privatefoo << std::endl;

	instance.publicbar();
	// instance._privatebar();

	return (0);
}
