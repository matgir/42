#include <iostream>

// Base class
class Animal
{
	public:
		Animal(const std::string& name) : name(name)
		{}

		void makeSound() const
		{
			std::cout << "Some generic sound\n";
		}

		void setName(const std::string& newName)
		{
			name = newName;
		}

		const std::string& getName() const
		{
			return name;
		}

	private:
		std::string name;
};

// Derived class
class Dog : public Animal
{
	public:
		// Constructor of the derived class can call the base class constructor
		Dog(const std::string& name) : Animal(name)
		{}

		// Override the makeSound method
		void makeSound() const
		{
			std::cout << "Woof!\n";
		}
};

// Another derived class
class Cat : public Animal
{
	public:
		Cat(const std::string& name) : Animal(name) 
		{}

		void makeSound() const 
		{
			std::cout << "Meow!\n";
		}
};

int main() {
	// Creating instances of the derived classes
	Dog myDog("Buddy");
	Cat myCat("Whiskers");

	// Accessing the inherited attributes and methods
	std::cout << myDog.getName() << " says ";
	myDog.makeSound();

	std::cout << myCat.getName() << " says ";
	myCat.makeSound();

	return 0;
}
