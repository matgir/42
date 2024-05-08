// replace canonical by your class name
// replace getvariable(void)const par nouveau getteur
// replace variable by your variable name

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:

		MutantStack< T >(void)
		{
			return;
		}
		MutantStack< T >(MutantStack< T > const & copy)
		{
			this->_stack = copy.getStack();
		}
		virtual ~MutantStack< T >(void)
		{
			return;
		}

		typedef std::iterator<T> iterator;
		typedef std::const_iterator<T> const_iterator;

		MutantStack	&operator=(MutantStack< T > const & assign)
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

		T				top(void)
		{
			return this->_stack.top();
		}

		void			push(T const & val)
		{
			this->_stack.push(val);
			return;
		}

		void			emplace(T const & args)
		{
			this->_stack.emplace(args);
			return;
		}

		void			pop(void)
		{
			this->_stack.pop();
			return;
		}

		void			swap(std::stack< T > & x)
		{
			this->_stack.swap(x);
			return;
		}

		iterator		begin(void)const
		{
			return this->_stack.top();
		}

		iterator		end(void)const
		{
			std::stack<T>	tmp = new this->_stack;

			for (tmp.size; tmp.size != 0; tmp.pop())
			return tmp;
		}

	private:

		std::stack<T> *	_stack;
};

#endif
