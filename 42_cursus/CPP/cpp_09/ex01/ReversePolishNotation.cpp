#include "ReversePolishNotation.hpp"

bool	isOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;
	else
		return false;
}

std::string	checkArg(std::string str)
{
	for (int i = str.size() - 2; i > 0; i-=2)
	{
		if (str[i] != ' ')
		{
			std::cout << "Error : wrong input, put a space inbetween each element" << std::endl;
			exit(1);
		}
		else
			str.erase(i, 1);
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
			exit(1);
		}
	}
	if (str.empty() || str.length() < 3 || !isdigit(str[0]) || !isdigit(str[1])
			|| !isOperator(str[str.length() - 1]))
	{
		std::cout << "Error : No possible way to calculate" << std::endl;
		exit(1);
	}
	if (nbOperator != nbValue - 1)
	{
		std::cout << "Error : the balance between the values and operators is not respected";
		std::cout << std::endl;
		exit(1);
	}

	return str;
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

double	printResult(std::stack<char> * myStack, bool * divByZero)
{
	char	op;
	double	right;
	double	left;

	if (isOperator(myStack->top()))
	{
		op = myStack->top();
		myStack->pop();
		right = printResult(myStack, divByZero);
		left = printResult(myStack, divByZero);
		if (*divByZero == true)
			return 0;
		if (op == '+')
			return left + right;
		else if (op == '-')
			return left - right;
		else if (op == '*')
			return left * right;
		else
		{
			if (right == 0)
			{
				std::cout << "Error : there was a division by ";
				*divByZero = true;
				return 0;
			}
			return left / right;
		}
	}
	else
	{
		left = myStack->top() - 48;
		myStack->pop();
		return left;
	}
}
