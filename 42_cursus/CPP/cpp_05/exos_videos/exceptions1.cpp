#include <stdexcept>

void	test1()
{
	try
	{
		{
			//Do some stuff here
			if (/* there's an error */)
			{
				throw std::exception();
			}
			else
			{
				//Do some stuff here
			}
		}
	}
	catch(const std::exception e)
	{
		// std::cerr << e.what() << '\n';
		//Handle the error here
	}
}

void	test2()
{
	//Do some stuff here
	if (/*  there's an error */)
	{
		throw std::exception();
	}
	else
	{
		//Do somme stuff here
	}
}

void	test3()
{
	try
	{
		test2;
	}
	catch(const std::exception& e)
	{
		// std::cerr << e.what() << '\n';
		//Handle error
	}
}

void	test4()
{
	class	PEBKACException : std::exception
	{
		public:
			virtual const char * what() const throw(/* ici ne renvoie rien mais on peut dfinir ce que ca renvoi, plus propre */)
			{
				return ("Problem exists between keyboard and chair");
			}
	};

	try
	{
		test3();
	}
	catch(PEBKACException& e)/* catch specifique */
	{
		// std::cerr << e.what() << '\n';
		//Handle the fact that the user is an idiot
	}
	catch(std::exception& e)/* catch generique */
	{
		//Handle other exeptions that are like std::execption
	}
}