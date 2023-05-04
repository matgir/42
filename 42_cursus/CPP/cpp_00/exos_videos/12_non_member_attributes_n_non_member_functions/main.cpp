/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 19:13:56 by mgirardo          #+#    #+#             */
/*   Updated: 2023/05/04 19:13:58 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "sample_class.hpp"

void	f0(void)
{
	Sample	instance;

	std::cout << "Number of instances = " << Sample::getnbinst() << std::endl;

	return;
}

void	f1(void)
{
	Sample	instance;

	std::cout << "Number of instances = " << Sample::getnbinst() << std::endl;
	f0();

	return;
}

int		main(void)
{
	std::cout << "Number of instances = " << Sample::getnbinst() << std::endl;
	f1();
	std::cout << "Number of instances = " << Sample::getnbinst() << std::endl;

	return (0);
}
