#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
	{
		const AAnimal	*j = new Dog();
		const AAnimal	*i = new Cat();
		// const AAnimal	*meta = new AAnimal();

		std::cout << j->getType() << std::endl;
		std::cout << i->getType() << std::endl;

		delete j;
		delete i;
		// delete meta;
	}
	return 0;
}
