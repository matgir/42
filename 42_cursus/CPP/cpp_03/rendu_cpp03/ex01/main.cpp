#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	{
		std::cout << "\e[0;32m//********** Energy limit test **********//\e[0;37m" << std::endl;
		ScavTrap	bob("bob");

		std::cout << "bob has " << bob.getEnergyPoints() << " Energy points" << std::endl;
		for (int i = 26; i >= 0; i--)
		{
			bob.attack("sylvie");
			bob.beRepaired(0);
		}
		std::cout << "bob has " << bob.getEnergyPoints() << " Energy points" << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	{
		std::cout << "\e[0;32m//********** Hit points limit test **********//\e[0;37m" << std::endl;
		ScavTrap	bob("bob");
		std::cout << "bob has " << bob.getEnergyPoints() << " Energy points" << std::endl;
		bob.takeDamage(100);
		std::cout << "bob has " << bob.getEnergyPoints() << " Energy points" << std::endl;
		bob.attack("sylvie");
		std::cout << "bob has " << bob.getEnergyPoints() << " Energy points" << std::endl;
		bob.beRepaired(0);
		std::cout << "bob has " << bob.getEnergyPoints() << " Energy points" << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	{
		std::cout << "\e[0;32m//********** Take damage test **********//\e[0;37m" << std::endl;
		ScavTrap	bob("bob");
		bob.takeDamage(1);
		bob.takeDamage(2);
		bob.takeDamage(3);
		bob.takeDamage(4);
		bob.takeDamage(100);
		bob.takeDamage(200);
	}
	std::cout << std::endl;
	std::cout << std::endl;
	{
		std::cout << "\e[0;32m//********** Repair test **********//\e[0;37m" << std::endl;
		ScavTrap	bob("bob");
		std::cout << "bob has " << bob.getEnergyPoints() << " Energy points" << std::endl;
		bob.beRepaired(1);
		std::cout << "bob has " << bob.getEnergyPoints() << " Energy points" << std::endl;
		bob.beRepaired(2);
		std::cout << "bob has " << bob.getEnergyPoints() << " Energy points" << std::endl;
		bob.beRepaired(3);
		std::cout << "bob has " << bob.getEnergyPoints() << " Energy points" << std::endl;
		bob.beRepaired(4);
		std::cout << "bob has " << bob.getEnergyPoints() << " Energy points" << std::endl;
		bob.beRepaired(5);
		std::cout << "bob has " << bob.getEnergyPoints() << " Energy points" << std::endl;
		bob.beRepaired(5);
		std::cout << "bob has " << bob.getEnergyPoints() << " Energy points" << std::endl;
		bob.beRepaired(UINT_MAX);
		std::cout << "bob has " << bob.getEnergyPoints() << " Energy points" << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	{
		std::cout << "\e[0;32m//********** Gate keeper mode test **********//\e[0;37m" << std::endl;
		ScavTrap	bob("bob");
		ClapTrap	yves("yves");

		bob.guardGate();
		// yves.guardGate(); //not possible because yves is only a claptrap
	}
	std::cout << std::endl;
	std::cout << std::endl;
	{
		std::cout << "\e[0;32m//********** copy assignment test **********//\e[0;37m" << std::endl;
		ScavTrap	bob("bob");
		ScavTrap	hughe("hughe");
		ClapTrap	yves("yves");
		ClapTrap	bertrand("bertrand");

		
		// bob = yves;	//possible but in need of coding another assignment operator dealing with ClapTrap
		hughe = bob;
		std::cout << "my new name is now " << hughe.getName() << std::endl;
		bertrand = yves;
		std::cout << "my new name is now " << bertrand.getName() << std::endl;
		yves = bob;	//possible but you lose some information from the child derived class
					//yves wont be able to use guardGate() but the base information will be transmited
		// yves.guardGate();
		yves.attack("someone");
		bob.attack("anoter someone");
		std::cout << "my new name is now " << yves.getName() << " and I have " << yves.getHitPoints() << " Hit points" << std::endl; 
	}
	std::cout << std::endl;
	std::cout << std::endl;
	{
		std::cout << "\e[0;32m//********** constructor test **********//\e[0;37m" << std::endl;
		ScavTrap	bob;
		ScavTrap	henri("Henri");
		ScavTrap	notHenri(henri);
	}
}