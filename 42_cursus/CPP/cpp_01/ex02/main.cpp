#include <iostream>

int	main()
{
	std::string		brain = "HI THIS IS BRAIN";
	std::string*	stringPTR = &brain;
	std::string&	stringREF = brain;
	std::string*	refPTR = &stringREF;

	std::cout << "Address of brain variable		= " << &brain << std::endl;
	std::cout << "Address pointed by stringPTR variable	= " << stringPTR << std::endl;
	std::cout << "Address reffed by stringREF variable	= " << &stringREF << std::endl;

	std::cout << "\nValue of brain variable			= " << brain << std::endl;
	std::cout << "Value pointed by stringPTR variable	= " << *stringPTR << std::endl;
	std::cout << "Value reffed by stringREF variable	= " << stringREF << std::endl;
	
	std::cout << "\nAddress of stringPTR variable		= " << &stringPTR << std::endl;
	std::cout << "Address of stringREF variable		= " << &stringREF << std::endl;
	std::cout << "Address pointed by refPTR variable	= " << refPTR << std::endl;
	std::cout << "Value pointed by refPTR			= " << *refPTR << std::endl;

	std::string		newbrain = "HI THIS IS NEWBRAIN";
	stringREF = newbrain;
	std::cout << "\nValue reffed by stringREF variable	= " << stringREF << std::endl;
	std::cout << "Value of brain variable			= " << brain << std::endl;
	std::cout << "Value of newbrain variable		= " << newbrain << std::endl;
	std::cout << "Address of brain variable		= " << &brain << std::endl;
	std::cout << "Address of newbrain variable		= " << &newbrain << std::endl;
	std::cout << "Address reffed by stringREF variable	= " << &stringREF << std::endl;
	std::cout << "Value pointed by refPTR			= " << *refPTR << std::endl;

	newbrain = "WATUP";
	brain = "YO YO YO";
	std::cout << "\nValue of newbrain variable		= " << newbrain << std::endl;
	std::cout << "Value of brain variable			= " << brain << std::endl;
	std::cout << "Value reffed by stringREF variable	= " << stringREF << std::endl;
	std::cout << "Value pointed by refPTR			= " << *refPTR << std::endl;

	return 0;
}