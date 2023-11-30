#include "ClapTrap.hpp"

int	main(void)
{
	{
//********** Energy limit test **********//
		ClapTrap	bob("bob");

		std::cout << "bob has " << bob.getEnergyPoints() << " Energy points" << std::endl;
		bob.attack("sylvie");
		std::cout << "bob has " << bob.getEnergyPoints() << " Energy points" << std::endl;
		bob.beRepaired(0);
		std::cout << "bob has " << bob.getEnergyPoints() << " Energy points" << std::endl;
		bob.attack("sylvie");
		std::cout << "bob has " << bob.getEnergyPoints() << " Energy points" << std::endl;
		bob.beRepaired(0);
		std::cout << "bob has " << bob.getEnergyPoints() << " Energy points" << std::endl;
		bob.attack("sylvie");
		std::cout << "bob has " << bob.getEnergyPoints() << " Energy points" << std::endl;
		bob.beRepaired(0);
		std::cout << "bob has " << bob.getEnergyPoints() << " Energy points" << std::endl;
		bob.attack("sylvie");
		std::cout << "bob has " << bob.getEnergyPoints() << " Energy points" << std::endl;
		bob.beRepaired(0);
		std::cout << "bob has " << bob.getEnergyPoints() << " Energy points" << std::endl;
		bob.attack("sylvie");
		std::cout << "bob has " << bob.getEnergyPoints() << " Energy points" << std::endl;
		bob.beRepaired(0);
		std::cout << "bob has " << bob.getEnergyPoints() << " Energy points" << std::endl;
		bob.attack("sylvie");
		std::cout << "bob has " << bob.getEnergyPoints() << " Energy points" << std::endl;
		bob.beRepaired(0);
		std::cout << "bob has " << bob.getEnergyPoints() << " Energy points" << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	{
//********** Hit points limit test **********//
		ClapTrap	bob("bob");
		std::cout << "bob has " << bob.getEnergyPoints() << " Energy points" << std::endl;
		bob.takeDamage(10);
		std::cout << "bob has " << bob.getEnergyPoints() << " Energy points" << std::endl;
		bob.attack("sylvie");
		std::cout << "bob has " << bob.getEnergyPoints() << " Energy points" << std::endl;
		bob.beRepaired(0);
		std::cout << "bob has " << bob.getEnergyPoints() << " Energy points" << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	{
//********** Take damage test **********//
		ClapTrap	bob("bob");
		bob.takeDamage(1);
		bob.takeDamage(2);
		bob.takeDamage(3);
		bob.takeDamage(4);
		bob.takeDamage(5);
		bob.takeDamage(5);
	}
	std::cout << std::endl;
	std::cout << std::endl;
	{
//********** Repair test **********//
		ClapTrap	bob("bob");
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
}