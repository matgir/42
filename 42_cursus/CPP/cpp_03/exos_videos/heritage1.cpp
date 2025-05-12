#include <string>

class	Cat
{
	private:

		int	_numberOfLegs;

	public:

		Cat();
		Cat(Cat const &);
		Cat &operator=(Cat const &);
		~Cat();

		void	run(int distance);

		void	scornSomeone(std::string const & target);
};

class	Pony
{
	private:

		int	numberOfLegs;

	public:

		Pony();
		Pony(Pony const &);
		Pony &operator=(Pony const &);
		~Pony();

		void	run(int distance);

		void	doMagic(std::string const & target);
};