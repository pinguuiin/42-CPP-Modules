#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	// default tests
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	delete dog;
	delete cat;
	std::cout << "\n" << std::endl;

	// more tests
	size_t i;
	Animal *animal[10];

	for (i = 0; i < 5; ++i)
		animal[i] = new Cat();
	for (i = 5; i < 10; ++i)
		animal[i] = new Dog();
	std::cout << std::endl;

	std::cout << "name: " << animal[2]->getType() << std::endl;
	animal[2]->makeSound();
	std::cout << "name: " << animal[6]->getType() << std::endl;
	animal[6]->makeSound();
	for (i = 0; i < 10; ++i)
		animal[i]->makeSound();
	std::cout << std::endl;

	for (i = 0; i < 10; ++i)
		delete animal[i];
	std::cout << std::endl;

	// Brain cell test
	Brain *oneBrainCell = new Brain();
	Brain *anotherBrainCell = new Brain();
	Brain *clonedBrain = new Brain(*oneBrainCell);

	*anotherBrainCell = *oneBrainCell;
	if (oneBrainCell != anotherBrainCell
		&& anotherBrainCell != clonedBrain
		&& oneBrainCell != clonedBrain)
		std::cout << "Copy is a deep copy ✅\n" << std::endl;

	delete oneBrainCell;
	delete anotherBrainCell;
	delete clonedBrain;

	return 0;
}
