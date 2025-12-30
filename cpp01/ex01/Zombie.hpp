#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {

	public:
		void announce(void);
		void setName(std::string name);

		Zombie();
		~Zombie();

	private:
		std::string name_;
};

Zombie  *zombieHorde(int N, std::string name);

#endif