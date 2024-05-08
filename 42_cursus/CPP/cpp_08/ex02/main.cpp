#include "MutantStack.hpp"
# include <iostream>

int main()
{
	std::cout << std::endl << std::endl;
	{
		/*	####	Subject test	####*/
		MutantStack<int>		mstack;
		mstack.push(5);
		mstack.push(17); 
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	std::cout << std::endl << std::endl;
	{
		/*	####	Test	####*/
		MutantStack<std::string>	mstack;
		
		mstack.push("premier");
		mstack.push("deuxieme");
		std::cout << "mstack.top() = " << mstack.top() << std::endl;
		std::cout << "mstack.size() = " << mstack.size() << std::endl;
		mstack.pop();
		std::cout << "mstack.size() = " << mstack.size() << std::endl;
		mstack.push("troisieme");
		mstack.push("quatrieme");
		mstack.push("cinquieme");

		MutantStack<std::string>	newStack = mstack;
		MutantStack<std::string>	swapStack;

		swapStack.push("NAN");
		// swapStack.swap(swapStack);
		swapStack.swap(newStack);
		std::cout << "swapStack.top() = " << swapStack.top() << std::endl;
		newStack.pop();
		std::cout << "mstack.top() = " << mstack.top() << std::endl;
		std::cout << "mstack.size() = " << mstack.size() << std::endl;
		std::cout << "newStack.top() = " << newStack.top() << std::endl;
		std::cout << "newStack.size() = " << newStack.size() << std::endl;
	}
	std::cout << std::endl << std::endl;
	return 0;
}
