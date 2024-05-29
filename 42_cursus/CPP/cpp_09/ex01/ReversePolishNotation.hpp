// replace canonical by your class name
// replace getvariable(void)const par nouveau getteur
// replace variable by your variable name

#ifndef REVERSEPOLISHNOTATION_HPP
# define REVERSEPOLISHNOTATION_HPP

# include <iostream>
# include <stack>

void				checkArg(std::string str);
std::stack<char>	createStack(std::string str);
void				printResult(std::stack<char> myStack);

#endif
