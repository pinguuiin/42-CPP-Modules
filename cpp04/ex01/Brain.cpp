#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; ++i) {
		ideas_[i] = "...";
	}
	std::cout << "A Brain is created!" << std::endl;
}

Brain::Brain(const Brain &other)
{
	*this = other;
	std::cout << "A Brain is created as a copy of another Brain!" << std::endl;
}

Brain	&Brain::operator=(const Brain &other)
{
	if (this != &other) {
		for (int i = 0; i < 100; ++i) {
			ideas_[i] = other.ideas_[i];
		}
	}
	std::cout << "A Brain is reassigned by another Brain!" << std::endl;
	return *this;
}

Brain::~Brain()
{
	std::cout << "This Brain is destroyed.." << std::endl;
}
