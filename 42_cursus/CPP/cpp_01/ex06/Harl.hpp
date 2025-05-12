#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>

class	Harl
{

	private:

		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

	public:

		Harl();
		~Harl();
		typedef void	(Harl::*complainptr)(void); //empty pointer on a function in Harl receiving void argument
		typedef struct s_Harl
		{
			std::string	level;
			complainptr	complain;
		} complainlist;
		void	complain(std::string level);
};

#endif