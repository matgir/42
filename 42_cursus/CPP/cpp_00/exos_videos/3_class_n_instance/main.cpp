/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:52:20 by mgirardo          #+#    #+#             */
/*   Updated: 2023/05/04 16:52:22 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "sample_class.hpp"

int	main()
{
	Sample instance;

	instance.exemple();
	std::cout << "instance de la class Sample instancié" << std::endl;

	return 0;
}
