#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
	{
		AAnimal	*j = new Dog();
		AAnimal	*i = new Cat();
		// AAnimal	*meta = new AAnimal();

		std::cout << j->getType() << std::endl;
		std::cout << i->getType() << std::endl;
		dynamic_cast<Dog*>(j)->getBrain()->setIdeas("* EAT MEOW *", 0);
		std::cout << dynamic_cast<Dog*>(j)->getBrain()->getIdeas(0) << std::endl;
		dynamic_cast<Dog*>(j)->makeSound();

		delete j;
		delete i;
		// delete meta;
	}
	return 0;
}
