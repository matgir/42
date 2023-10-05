/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ref2.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:56:41 by mgirardo          #+#    #+#             */
/*   Updated: 2023/10/05 17:56:42 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void	byPtr(std::string* str)
{
	*str+= " and ponies";
}

void	byConstPtr(std::string const * str)
{
	std::cout << *str << std::endl;
}

void	byRef(std::string& str)
{
	str += " and ponies";
}

void	byConstRef(std::string const & str)
{
	std::cout << str << std::endl;
}

int	main()
{
	std::string str = "i like butterflies";

	std::cout << str << std::endl;
	byPtr(&str);
	byConstPtr(&str);

	str = "i like otters";

	std::cout << str << std::endl;
	byRef(str);
	byConstRef(str);

	return(0);
}
