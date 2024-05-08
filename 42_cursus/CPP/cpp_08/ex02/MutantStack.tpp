#include "MutantStack.hpp"

template<typename T>
MutantStack< T >(void)
{
	return;
}
template<typename T>
MutantStack< T >(MutantStack< T > const & copy)
{
	this->_stack = copy.getStack();
}
template<typename T>
virtual ~MutantStack< T >(void)
{
	return;
}

template<typename T>
MutantStack	&MutantStack::operator=(MutantStack< T > const & assign)
{
	if (this != &assign)
		this->_stack = assign.getStack();
	return *this;
}

template<typename T>
std::stack<T>	MutantStack::getStack(void)const
{
	return this->_stack;
}

bool			MutantStack::empty(void)const
{
	return this->_stack.empty();
}

unsigned int	MutantStack::size(void)const
{
	return this->_stack.size();
}

template<typename T>
T				MutantStack::top(void)
{
	return this->_stack.top();
}

template<typename T>
void			MutantStack::push(const T & val)
{
	this->_stack.push(val);
	return;
}

template<typename T>
void			MutantStack::emplace(const T & args)
{
	this->_stack.emplace(args);
	return;
}

void			MutantStack::pop(void)
{
	this->_stack.pop();
	return;
}

template<typename T>
void			MutantStack::swap(std::stack< T > & x)
{
	this->_stack.swap(x);
	return;
}
