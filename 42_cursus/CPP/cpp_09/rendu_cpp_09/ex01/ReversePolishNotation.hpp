#ifndef REVERSEPOLISHNOTATION_HPP
# define REVERSEPOLISHNOTATION_HPP

# include <iostream>
# include <stack>
# include <stdlib.h>

std::string			checkArg(std::string str, bool * isThereProblem);
std::stack<char>	createStack(std::string str);
double				printResult(std::stack<char> * myStack, bool * divByZero);

#endif
