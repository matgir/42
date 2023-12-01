#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	{
		std::cout << "//********** Energy limit test **********//" << std::endl;
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
		std::cout << "//********** Hit points limit test **********//" << std::endl;
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
		std::cout << "//********** Take damage test **********//" << std::endl;
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
		std::cout << "//********** Repair test **********//" << std::endl;
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
		std::cout << "//********** Gate keeper mode test **********//" << std::endl;
		ScavTrap	bob("bob");
		ClapTrap	yves("yves");

		bob.guardGate();
		// yves.guardGate();
	}
	std::cout << std::endl;
	std::cout << std::endl;
	{
		std::cout << "//********** copy assignment test **********//" << std::endl;
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
		std::cout << "my new name is now " << yves.getName() << " and I have " << yves.getHitPoints() << " Hit points" << std::endl; 
	}
}