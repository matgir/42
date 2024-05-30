#include "ReversePolishNotation.hpp"

int	main(int argc, char ** argv)
{
	if (argc != 2)
	{
		std::cout << "Error : wrong number of arguments" << std::endl;
		return 0;
	}
	
	std::string	calculus(argv[1]);

	calculus = checkArg(calculus);
	
	std::stack<char>	myStack = createStack(calculus);

	std::cout << printResult(&myStack) << std::endl;

	return 0;
}