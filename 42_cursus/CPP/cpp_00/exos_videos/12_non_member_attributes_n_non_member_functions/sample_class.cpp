/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sample_class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:14:04 by mgirardo          #+#    #+#             */
/*   Updated: 2023/05/04 19:14:05 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "sample_class.hpp"

Sample::Sample(void)
{
	std::cout << "Constructor called" << std::endl;
	Sample::_nbinst += 1;

	return;
}

Sample::~Sample(void)
{
	std::cout << "Destructor called" << std::endl;
	Sample::_nbinst -= 1;

	return;
}

int	Sample::getnbinst(void)
{
	return (Sample::_nbinst);
	// return (this->_nbinst);
}

int	Sample::_nbinst = 0;
