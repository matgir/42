#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void)
{
	{
//********** Energy limit test **********//
		DiamondTrap	bob("bob");

		std::cout << "bob has " << bob.getEnergyPoints() << " Energy points" << std::endl;
		for (int i = 51; i >= 0; i--)
		{
			bob.attack("sylvie");
			bob.beRepaired(0);
			if (i == 24)
				std::cout << "bob has " << bob.getEnergyPoints() << " Energy points" << std::endl;
		}
		std::cout << "bob has " << bob.getEnergyPoints() << " Energy points" << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	{
//********** Hit points limit test **********//
		DiamondTrap	bob("bob");
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
//********** Take damage test **********//
		DiamondTrap	bob("bob");
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
//********** Repair test **********//
		DiamondTrap	bob("bob");
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
//********** Value check **********//
		ScavTrap	henri("henri");
		FragTrap	paul("paul");
		DiamondTrap	patrick("patrick");

		std::cout << patrick.getName() << " has " << patrick.getHitPoints() << " Hits points\n";
		std::cout << paul.getName() << " has " << paul.getHitPoints() << " Hits points\n";


		std::cout << patrick.getName() << " has " << patrick.getEnergyPoints() << " Energy points\n";
		std::cout << henri.getName() << " has " << henri.getEnergyPoints() << " Energy points\n";

		std::cout << patrick.getName() << " has " << patrick.getAttackDamage() << " Attack damage\n";
		std::cout << paul.getName() << " has " << paul.getAttackDamage() << " Attack damage\n";
	}
	std::cout << std::endl;
	std::cout << std::endl;
	{
//********** Gate keeper mode/high five test **********//
		ScavTrap	bob("bob");
		ClapTrap	yves("yves");
		FragTrap	jean("jean");
		DiamondTrap	bertand("bertrand");

		bob.guardGate();
		// yves.guardGate();
		// jean.guardGate();

		jean.highFiveGuys();
		// yves.highFiveGuys();
		// bob.highFiveGuys();

		bertand.guardGate();
		bertand.highFiveGuys();
		bertand.whoAmI();
	}
	std::cout << std::endl;
	std::cout << std::endl;
	{
//********** copy assignment test **********//
		ScavTrap	bob("bob");
		ScavTrap	hughe("hughe");
		ClapTrap	yves("yves");
		ClapTrap	bertrand("bertrand");
		FragTrap	bill("bill");
		FragTrap	boule("boule");

		
		// bob = yves;	//possible but in need of coding another assignment operator dealing with ClapTrap
		
		hughe = bob;
		std::cout << "my new name is now " << hughe.getName() << std::endl;
		
		bertrand = yves;
		std::cout << "my new name is now " << bertrand.getName() << std::endl;
		
		yves = bob;	//possible but you lose some information from the child derived class
					//yves wont be able to use guardGate() but the base information will be transmited
		// yves.guardGate();
		std::cout << "my new name is now " << yves.getName() << " and I have " << yves.getHitPoints() << " Hit points" << std::endl; 

		// bob = bill;	//possible but in need of coding another assignment operator dealing with FragTrap
		// bill = bob;	//possible but in need of coding another assignment operator dealing with ScavTrap
		// bill = yves;	//possible but in need of coding another assignment operator dealing with ClapTrap
		
		boule = bill;
		std::cout << "my new name is now " << boule.getName() << std::endl;

		bertrand = bill;	//possible but you lose some information from the child derived class
							//bertrand wont be able to use guardGate() but the base information will be transmited
		// bertrand.guardGate();
		std::cout << "my new name is now " << bertrand.getName() << " and I have " << bertrand.getEnergyPoints() << " Energy points" << std::endl; 
	}
}