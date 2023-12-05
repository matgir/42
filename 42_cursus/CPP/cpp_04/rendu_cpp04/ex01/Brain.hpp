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

		Brain			&operator=(Brain const & assign);

		std::string		getIdeas(const int & i)const;
		void			setIdeas(const std::string & idea, const int & i);

	private:

		std::string		_ideas[100];
};

#endif
