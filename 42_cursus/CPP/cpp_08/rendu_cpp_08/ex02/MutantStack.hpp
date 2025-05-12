// replace canonical by your class name
// replace getvariable(void)const par nouveau getteur
// replace variable by your variable name

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template<typename T>
class MutantStack : public std::stack <T>
{
	public:

		typedef typename std::stack<T>::container_type::iterator	iterator;

		MutantStack< T >(void)
		{
			return;
		}
		MutantStack< T >(MutantStack< T > const & copy) : std::stack<T>(copy)
		{
			return;
		}
		virtual ~MutantStack< T >(void)
		{
			return;
		}

		MutantStack	&operator=(MutantStack< T > const & assign)
		{
			if (this != &assign)
				this->c = assign.c;
			return *this;
		}

		iterator		begin(void)
		{
			return this->c.begin();
		}

		iterator		end(void)
		{
			return this->c.end();
		}

};

#endif
