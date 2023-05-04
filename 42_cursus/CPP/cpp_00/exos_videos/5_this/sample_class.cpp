/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample_class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:53:24 by mgirardo          #+#    #+#             */
/*   Updated: 2023/05/04 16:53:26 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "sample_class.hpp"

Sample::Sample(void)
{
	std::cout << "Constructor called" << std::endl;

	this->foo = 42;
	std::cout << "this->foo = " << this->foo << std::endl;

	this->bar();

	return;
}

Sample::~Sample(void)
{
	this->foo = 77;
	std::cout << "this->foo = " << this->foo << std::endl;

	std::cout << "Destructor called" << std::endl;
	return;
}

void Sample::bar(void)
{
	std::cout << "Member function 'bar' called" << std::endl;
	this->foo++;
	std::cout << "this->foo = " << this->foo << std::endl;
	return;
}
