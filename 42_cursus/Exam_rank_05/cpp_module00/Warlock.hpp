#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <iostream>
# include <string>

class Warlock
{
	public:
		Warlock(std::string name, std::string title);
		virtual ~Warlock(void);

		std::string const &	getName(void)const;
		std::string const &	getTitle(void)const;
		void				setTitle(std::string const & newTitle);
		void				introduce(void)const;

	private:
		Warlock(void);
		Warlock(Warlock const & copy);
		Warlock	&operator=(Warlock const & assign);

		std::string	_name;
		std::string	_title;
};

#endif
