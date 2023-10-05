/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ref1.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:56:33 by mgirardo          #+#    #+#             */
/*   Updated: 2023/10/05 17:56:34 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main()
{
	int	numberOfBalls = 42;

	int*	ballsPtr = &numberOfBalls;
	int&	ballsRef = numberOfBalls;

	std::cout << numberOfBalls << " " << *ballsPtr <<  " " << ballsRef<< std::endl;

	*ballsPtr = 21;
	std::cout << numberOfBalls << std::endl;
	ballsRef = 84;
	std::cout << numberOfBalls << std::endl;

	return(0);
}
