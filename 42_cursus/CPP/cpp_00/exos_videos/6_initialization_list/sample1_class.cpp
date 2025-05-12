/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample1_class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:53:52 by mgirardo          #+#    #+#             */
/*   Updated: 2023/05/04 16:53:53 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "sample1_class.hpp"

Sample1::Sample1(char p1, int p2, float p3)
{
	std::cout << "Constructor called" << std::endl;

	this->a1 = p1;
	std::cout << "this1->a1 = " << this->a1 << std::endl;
	this->a1++;
	std::cout << "this1->a1 = " << this->a1 << std::endl;

	this->a2 = p2;
	std::cout << "this1->a2 = " << this->a2 << std::endl;
	this->a2++;
	std::cout << "this1->a2 = " << this->a2 << std::endl;

	this->a3 = p3;
	std::cout << "this1->a3 = " << this->a3 << std::endl;
	this->a3++;
	std::cout << "this1->a3 = " << this->a3 << std::endl;

	return;
}

Sample1::~Sample1(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}
