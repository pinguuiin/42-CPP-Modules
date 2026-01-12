#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	const WrongAnimal* antimeta = new WrongAnimal();
	const WrongAnimal* nomewcat = new WrongCat();

	std::cout << "\nBio divisions:" << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	std::cout << antimeta->getType() << " " << std::endl;

	std::cout << "\nSpecies:" << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	std::cout << nomewcat->getType() << " " << std::endl;

	std::cout << "\nFarm:" << std::endl;
	meta->makeSound();
	cat->makeSound();
	dog->makeSound();

	std::cout << "\nWrongFarm:" << std::endl;
	antimeta->makeSound();
	nomewcat->makeSound();

	std::cout << std::endl;
	delete meta;
	delete dog;
	delete cat;
	delete antimeta;
	delete nomewcat;

	return 0;
}
