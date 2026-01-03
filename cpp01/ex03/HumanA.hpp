#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA {

	public:
		void attack() const;

		HumanA(std::string name, Weapon &weapon);

	private:
		std::string name_;
		Weapon &weapon_;
};

#endif
