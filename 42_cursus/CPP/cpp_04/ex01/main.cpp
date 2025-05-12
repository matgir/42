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
		int		j = 6;
		Animal	*animals[j];
		
		for(int i = 0; i < j; i++)
		{
			if (i % 2 == 0)
				animals[i] = new Dog();
			else
				animals[i] = new Cat();
		}

		animals[0]->makeSound(); //makes dog sound
		animals[3]->makeSound(); //makes cat sound
		dynamic_cast<Dog*>(animals[0])->getBrain()->setIdeas("* EAT MEOW *", 0);
		std::cout << dynamic_cast<Dog*>(animals[0])->getBrain()->getIdeas(0) << std::endl;

		for (int i = 0; i < j; i++)
			delete animals[i];
	}
	std::cout << std::endl << std::endl;
	{
		const Dog	*dog1 = new Dog();
		dog1->getBrain()->setIdeas("dog1 idea 1", 0);
		dog1->getBrain()->setIdeas("dog1 idea 2", 1);
		const Dog	*dog2 = new Dog(*dog1);
		// const Dog	*dog2 = new Dog();
		// dog2 = dog1;
		dog2->getBrain()->setIdeas("I AM DOG 2", 0);
		std::cout << dog1->getBrain()->getIdeas(0) << std::endl;
		std::cout << dog2->getBrain()->getIdeas(0) << std::endl;
		delete dog1;
		delete dog2;
	}
	return 0;
}
