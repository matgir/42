#include <string>

class	Quadruped
{
	//can acces name, run() and legs
	private:

		std::string	name; //Only accessible by a Quadruped object

	protected:

		Leg	legs[4]; //Accessible from a Quadruped and/or derived object

	public:

		void	run(); //Accessible from whereever
};

class	Dog : public Quadruped
{
//Can acces run() and legs
};

int	main(void)
{
//Can acces run()
}