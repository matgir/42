/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new2.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:56:24 by mgirardo          #+#    #+#             */
/*   Updated: 2023/10/05 17:56:26 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

class	Student
{
	private:
		std::string	_login;

	public:
		Student() : _login("ldefault")
	{
		std::cout << "Student " << this->_login << " is born" << std::endl;
	}

		~Student()
		{
			std::cout << "Student " << this->_login << " died" << std::endl;
		}

		void	announce()
		{
			std::cout << "I " << this->_login << " announce" << std::endl;
		}
};

int	main()
{
	Student*	students = new Student[42];

	students[0].announce();
	//students[-45].announce();
	// Do some stuff here

	delete [] students;
}
