#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int	main()
{
	{
		Weapon	club = Weapon("crude skiked club");
		std::cout << "Weapon type : " << club.getType() << std::endl;
		std::cout << std::endl;

		HumanA	bob("Bob", club);
		bob.getname();
		bob.attack();
		club.setType("some other type of club");
		std::cout << "Weapon type : " << club.getType() << std::endl;
		bob.attack();
		std::cout << std::endl;
	}
	{
		Weapon	club = Weapon("crude spiked club");
		std::cout << "Weapon type : " << club.getType() << std::endl;
		std::cout << std::endl;

		HumanB	jim("Jim");
		jim.getname();
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		std::cout << "Weapon type : " << club.getType() << std::endl;
		jim.attack();
		std::cout << std::endl;

		Weapon	riffle = Weapon("AK 47");
		std::cout << "Weapon type : " << riffle.getType() << std::endl;
		jim.setWeapon(riffle);
		jim.attack();
		riffle.setType("snipper");
		std::cout << "Weapon type : " << riffle.getType() << std::endl;
		jim.attack();
	}
	return (0);
}