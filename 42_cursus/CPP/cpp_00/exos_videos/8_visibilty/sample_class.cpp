/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample_class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:55:01 by mgirardo          #+#    #+#             */
/*   Updated: 2023/05/04 16:55:02 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "sample_class.hpp"

Sample::Sample(void)
{
	std::cout << "Constructor called" << std::endl;

	this->publicfoo = 0;
	std::cout << "this->publicfoo = " << this->publicfoo << std::endl;
	this->_privatefoo = 0;
	std::cout << "this->_privatefoo = " << this->_privatefoo << std::endl;

	this->publicbar();
	this->_privatebar();

	return;
}

Sample::~Sample(void)
{
	this->_privatefoo++;
	std::cout << "this->_privatefoo = " << this->_privatefoo << std::endl;
	std::cout << "Destructor called" << std::endl;
	return;
}

void	Sample::publicbar(void)const
{
	std::cout << "Member function publicbar called" << std::endl;
	return;
}

void	Sample::_privatebar(void)const
{
	// this->_privatefoo++;
	// std::cout << "this->_privatefoo = " << this->_privatefoo << std::endl;
	std::cout << "memeber function _privatebar called" << std::endl;
	return;
}
