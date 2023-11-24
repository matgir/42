#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
	{
		const Animal	*j = new Dog();
		const Animal	*i = new Cat();

		delete j;
		delete i;
	}
	std::cout << std::endl << std::endl;
	{
		Animal	*animals[10];
		
		for(int i = 0; i < 10; i++)
		{
			if (i % 2 == 0)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
		}

		animals[0]->makeSound(); //makes dog sound
		animals[3]->makeSound(); //makes cat sound

		for (int i = 0; i < 10; i++)
			delete animals[i];
	}
	std::cout << std::endl << std::endl;
	{
		Dog	dog1 = Dog();
		dog1.getBrain()->setIdeas("dog1 idea 1", 0);
		dog1.getBrain()->setIdeas("dog1 idea 2", 1);
		Dog	dog2 = Dog(dog1);
		dog2.getBrain()->setIdeas("dog2 idea 1", 0);
		std::cout << dog1.getBrain()->getIdeas(0) << std::endl;
		std::cout << dog2.getBrain()->getIdeas(0) << std::endl;
	}
	return 0;
}
