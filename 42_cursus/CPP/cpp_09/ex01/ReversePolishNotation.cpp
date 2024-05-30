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
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == ' ')
			str.erase(i, 1);
	}
	if (str.empty() || str.length() < 3 || !isdigit(str[0]) || !isdigit(str[1])
			|| !isOperator(str[str.length() - 1]))
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

int	printResult(std::stack<char> * myStack)
{
	char	op;
	int		right;
	int		left;
	int		result;

	// while (!myStack->empty())
	// {
	if (isOperator(myStack->top()))
	{
		op = myStack->top();
		myStack->pop();
		right = printResult(myStack);
		if (op == '+')
		{//
			right = (myStack->top() - 48) + right;
			myStack->pop();
			return right;
		}//
		else if (op == '-')
		{//
			right = (myStack->top() - 48) - right;
			myStack->pop();
			return right;
		}//
		else if (op == '*')
		{//
			right = (myStack->top() - 48) * right;
			myStack->pop();
			return right;
		}//
		else
		{//
			/* if divided by 0 send error */
			right = (myStack->top() - 48) / right;
			myStack->pop();
			return right;
		}//
	}
	else
	{
		i = myStack->top() - 48;
		myStack->pop();
		if (!isOperator(myStack->top()))
			return i;
		else
		{
			op = myStack->top();
			myStack->pop();
			int	j = printResult(myStack);
			if (op == '+')
			{//
				j = j + i;
				myStack->pop();
				return j;
			}//
			else if (op == '-')
			{//
				j = j - i;
				myStack->pop();
				return j;
			}//
			else if (op == '*')
			{//
				j = j * i;
				myStack->pop();
				return j;
			}//
			else
			{//
				/* if divided by 0 send error */
				j = j / i;
				myStack->pop();
				return j;
			}//
			/* #### trouver solution pour continuer quand apres num cest operator #### */
		}
		// return i;
	}
	// }

}
