/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample2_class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:54:13 by mgirardo          #+#    #+#             */
/*   Updated: 2023/05/04 16:54:14 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "sample2_class.hpp"

Sample2::Sample2(char p1, int p2, float p3) : a1(p1),
		a2(p2), a3(p3)
{
	std::cout << "Constructor called" << std::endl;
	std::cout << "this->a1 = " << this->a1 << std::endl;
	this->a1++;
	std::cout << "this->a1 = " << this->a1 << std::endl;
	std::cout << "this->a2 = " << this->a2 << std::endl;
	this->a2++;
	std::cout << "this->a2 = " << this->a2 << std::endl;
	std::cout << "this->a3 = " << this->a3 << std::endl;
	this->a3++;
	std::cout << "this->a3 = " << this->a3 << std::endl;
	return;
}

Sample2::~Sample2(void)
{
	std::cout << "Destructor called" << std::endl;
	return;
}
