#include "ReversePolishNotation.hpp"

int	main(int argc, char ** argv)
{
	std::cout << std::endl << std::endl;//
	if (argc != 2)
	{
		std::cout << "Error : wrong number of arguments" << std::endl;
		std::cout << std::endl << std::endl;//
		return 1;
	}
	
	std::string	calculus(argv[1]);
	bool		isThereProblem = false;

	calculus = checkArg(calculus, &isThereProblem);
	if (isThereProblem == true)
		return 1;
	
	std::stack<char>	myStack = createStack(calculus);

	bool	divByZero = false;
	// int		level = 0;
	double	result = printResult(&myStack, &divByZero);
	// double	result = printResult(&myStack, &divByZero, level);

	if (myStack.empty())
		std::cout << result << std::endl;
	else
		std::cout << "Error : there was an error in the calculation" << std::endl;

	// std::cout << result << std::endl;
	std::cout << std::endl << std::endl;//

	return 1;
}