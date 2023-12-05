// replace Brain by your class name
// replace ideas by your ideas name

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
	public:

		Brain(void);
		Brain(Brain const & copy);
		~Brain(void);

		Brain	&operator=(Brain const & assign);

		std::string		getIdeas(int i)const;
		void			setIdeas(std::string idea, int i);

	private:

		std::string		_ideas[100];
};

#endif
