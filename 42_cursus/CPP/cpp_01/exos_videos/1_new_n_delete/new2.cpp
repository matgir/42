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
};

int	main()
{
	Student*	students = new Student[42];

	// Do some stuff here

	delete [] students;
}
