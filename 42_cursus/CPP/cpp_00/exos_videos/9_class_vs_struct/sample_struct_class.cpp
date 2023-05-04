/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample_struct_class.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:55:35 by mgirardo          #+#    #+#             */
/*   Updated: 2023/05/04 16:55:36 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "sample_struct.hpp"
#include "sample_class.hpp"

Sample1::Sample1(void)
{
	std::cout << "Constructor 1 called" << std::endl;
	this->bar1();
	return;
}

Sample1::~Sample1(void)
{
	std::cout << "Destructor 1 called" << std::endl;
	return;
}

void	Sample1::bar1(void)const
{
	std::cout << "Member function bar1 called" << std::endl;
	return;
}

Sample2::Sample2(void)
{
	std::cout << "Constructor 2 called" << std::endl;
	this->bar2();
	return;
}

Sample2::~Sample2(void)
{
	std::cout << "Destructor 2 called" << std::endl;
	return;
}

void	Sample2::bar2(void)const
{
	std::cout << "Member function bar2 called" << std::endl;
	return;
}
