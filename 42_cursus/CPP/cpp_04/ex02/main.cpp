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

		delete j;
		delete i;
		// delete meta;
	}
	return 1;
}
