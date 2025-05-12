/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample_class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:56:15 by mgirardo          #+#    #+#             */
/*   Updated: 2023/05/04 16:56:19 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "sample_class.hpp"

Sample::Sample(void)
{
	std::cout << "Constructeur called" << std::endl;

	this->setfoo(0);
	std::cout << "this->getfoo(): " << this->getfoo() << std::endl;

	return;
}

Sample::~Sample(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}

int	Sample::getfoo(void)const
{
	return this->_foo;
}

void	Sample::setfoo(int v)
{
	if (v >= 0)
		this->_foo = v;
	else
		std::cout << "Could not set _foo because " << v << " is below 0" << std::endl;

	return;
}
