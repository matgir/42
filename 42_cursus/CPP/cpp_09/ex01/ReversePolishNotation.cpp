#include "ReversePolishNotation.hpp"

bool	isOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	else
		return false;
}

void	checkArg(std::string str)
{
	/* #### ajouter le retrait des espaces #### */
	if (str.empty() || str.length() < 3 || !isdigit(str[0]) || !isdigit(str[1]
			|| !isOperator(str[str.length() - 1])))
	{
		std::cout << "Error : No possible way to calculate" << std::endl;
		exit(0);
	}

	unsigned int	nbValue = 0;
	unsigned int	nbOperator = 0;

	for (int i = 0; str[i]; i++)
	{
		if (isdigit(str[i]))
			nbValue++;
		else if (isOperator(str[i]))
			nbOperator++;
		else
		{
			std::cout << "Error : <" << str[i] << "> invalid character" << std::endl;
			exit(0);
		}
	}

	if (nbOperator != nbValue - 1)
	{
		std::cout << "Error : the balance between the values and operators is not respected";
		std::cout << std::endl;
		exit(0);
	}

	return;
}

std::stack<char>	createStack(std::string str)
{
	std::stack<char>	myStack;

	for (int i = 0; str[i]; i++)
	{
		myStack.push(str[i]);
	}
	
	return myStack;
}

void	printResult(std::stack<char> myStack)
{

}
