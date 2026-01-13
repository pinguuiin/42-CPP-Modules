#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	// const Animal* meta = new Animal(); ==> error
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << "\nSpecies: "
			  << dog->getType() << ", "
			  << cat->getType() << std::endl;

	std::cout << "\nFarm:" << std::endl;
	cat->makeSound();
	dog->makeSound();

	std::cout << std::endl;
	delete dog;
	delete cat;

	return 0;
}
