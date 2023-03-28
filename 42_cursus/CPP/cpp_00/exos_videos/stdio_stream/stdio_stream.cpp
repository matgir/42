/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stdio_stream.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:13:19 by mgirardo          #+#    #+#             */
/*   Updated: 2023/03/21 17:13:20 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	char	buf[512];
	std::cout << "Hello World !" << std::endl;

	std::cout << "Input a word : ";
	std::cin >> buf;
	std::cout << "You entered : [ " << buf << " ]" << std::endl;

	return (0);
} 