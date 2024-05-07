// replace canonical by your class name
// replace getvariable(void)const par nouveau getteur
// replace variable by your variable name

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template<typename T>
class MutantStack
{
	public:

		MutantStack< T >(void)
		{
			return;
		}
		MutantStack< T >(MutantStack< T > const & copy)
		{
			this->_stack = this->getStack();
		}
		virtual ~MutantStack< T >(void)
		{
			return;
		}

		MutantStack	&operator=(MutantStack const & assign)
		{
			if (this != &assign)
				this->_stack = assign.getStack();
			return *this;
		}

		std::stack<T>	getStack(void)const
		{
			return this->_stack;
		}

		bool			empty(void)const
		{
			return this->_stack.empty();
		}

		unsigned int	size(void)const
		{
			return this->_stack.size();
		}

		template<typename T>
		T				top(void)
		{
			return this->_stack.top();
		}

		template<typename T>
		void			push(T & val)
		{
			this->_stack.push(val);
			return;
		}

		template<typename T>
		void			emplace(T & args)
		{
			this->_stack.emplace(args);
			return;
		}

		void			pop(void)
		{
			this->_stack.pop();
			return;
		}

		void			swap(std::stack & x)
		{
			this->_stack.swap(x);
			return;
		}

	private:

		std::stack<T> *	_stack;
};

#endif

// #include "MutantStack.hpp"

// MutantStack::MutantStack(void) : _variable(0)
// {
// 	std::cout << "MutantStack default constructor called" << std::endl;
// 	return;
// }

// MutantStack::MutantStack(MutantStack const & copy)
// {
// 	std::cout << "MutantStack copy constructor called" << std::endl;
// 	this->_variable = copy.getvariable();
// 	return;
// }

// MutantStack::~MutantStack(void)
// {
// 	std::cout << "MutantStack destructor called" << std::endl;
// 	return;
// }

// MutantStack	&MutantStack::operator=(MutantStack const & assign)
// {
// 	std::cout << "MutantStack assignment operator called" << std::endl;

// 	if (this != &assign)
// 		this->_variable = assign.getvariable();

// 	return *this;
// }
