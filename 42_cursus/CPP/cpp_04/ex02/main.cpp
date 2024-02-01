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
		Dog		*d = new Dog();
		Dog		*f = new Dog(*d);

		std::cout << j->getType() << std::endl;
		std::cout << i->getType() << std::endl;
		std::cout << d->getType() << std::endl;
		std::cout << f->getType() << std::endl;
		dynamic_cast<Dog*>(j)->getBrain()->setIdeas("* EAT MEOW *", 0);
		std::cout << dynamic_cast<Dog*>(j)->getBrain()->getIdeas(0);
		std::cout << std::endl;

		d->getBrain()->setIdeas(" * DDDDDDDDD * ", 0);
		std::cout << d->getBrain()->getIdeas(0) << std::endl;

		Dog	*g = d;
		// Dog	*g = dynamic_cast<Dog*>(j);
		std::cout << g->getType() << std::endl;
		dynamic_cast<Dog*>(g)->getBrain()->setIdeas("* I am GG *", 0);
		std::cout << dynamic_cast<Dog*>(d)->getBrain()->getIdeas(0);
		std::cout << std::endl;

		dynamic_cast<Dog*>(j)->makeSound();

		delete j;
		delete i;
		delete d;
		delete f;
		delete g;
		// delete meta;
	}
	return 0;
}
