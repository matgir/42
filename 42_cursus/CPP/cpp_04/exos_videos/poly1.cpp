#include <string>
#include <iostream>

class Character
{
	public:
		virtual void	sayHello(std::string const & target);
		// void	sayHello(std::string const & target);
};

class Warrior : public Character
{
	public:
		virtual void	sayHello(std::string const & target);
		// void	sayHello(std::string const & target);
};

class Cat
{
	// [...]
};

void	Character::sayHello(std::string const & target)
{
	std::cout << "Hello " << target << " !" << std::endl;
}

void	Warrior::sayHello(std::string const & target)
{
	std::cout << "F*** off " << target << ", I don't like you !" << std::endl;
}

int	main(void)
{
	// this is ok, obviously, Warrior is a Warrior
	Warrior*	a = new Warrior();

	// this is ok, obviously, Warrior is a Character
	Character*	b = new Warrior();

	// this is not ok because Character is not a Warrior
	// they are related and Warrior is a Character, the inverse is not true
	// Warrior*	c = new Character();

	// this is not ok, Cat is in no way related to Character
	// Character*	d = new Cat();

	a->sayHello("student");

	b->sayHello("student");
}