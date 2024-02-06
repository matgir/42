#include "Ice.hpp"
#include "Water.hpp"
#include "Mud.hpp"
#include "Fire.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main()
{
	std::cout << std::endl << std::endl;
	{
		IMateriaSource * src = new MateriaSoucre();
		AMateria* tmp;

		tmp = new Ice();
		src->learnMateria(tmp);
		delete tmp;
		tmp = new Cure();
		src->learnMateria(tmp);
		delete tmp;

		ICharacter * me = new Character("me");

		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter * bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}
	std::cout << std::endl << std::endl;
	{
		ICharacter *	random = new Character("Bernard");

		random->getName();

		random->equip(new Ice());
		random->equip(new Mud());
		random->equip(new Water());
		random->equip(new Fire());

		random->unequip(0);
		random->unequip(0);
		random->unequip(27);

		random->equip(new Fire());
		random->equip(new Cure());
		random->equip(new Ice());

		random->use(0, *random);
		random->use(1, *random);
		random->use(2, *random);
		random->use(3, *random);

		delete random;
	}
	std::cout << std::endl << std::endl;
	{
		IMateriaSource *	src = new MateriaSoucre();
		ICharacter *		bernard = new Character("Bernard");
		AMateria *			tmp;

		src->learnMateria(new Mud());
		src->learnMateria(new Mud());

		bernard->equip(src->createMateria("mud"));
		bernard->equip(src->createMateria("fire"));

		dynamic_cast<MateriaSoucre*>(src)->getMateria(3);
		
		src->learnMateria(new Fire());

		bernard->equip(src->createMateria("fire"));

		src->learnMateria(new Fire());
		src->learnMateria(new Fire());
		src->learnMateria(NULL);

		delete bernard;
		delete src;
	}
	std::cout << std::endl << std::endl;
	return 0;
}

