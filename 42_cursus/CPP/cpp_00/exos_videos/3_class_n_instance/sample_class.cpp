/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample_class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:42:13 by mgirardo          #+#    #+#             */
/*   Updated: 2023/05/04 16:52:33 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "sample_class.hpp"

Sample::Sample(void)
{
	std::cout << "Constructor called" << std::endl;
	return;
}

Sample::~Sample(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

/* void	Sample::exemple(void)
{
	std::cout << "instance de la class Sample instancié" << std::endl;
	return;
} */
