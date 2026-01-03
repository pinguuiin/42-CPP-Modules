#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB {

	public:
		void attack() const;
		void setWeapon(Weapon &weapon);

		HumanB(std::string name);

	private:
		std::string name_;
		Weapon *weapon_;
};

#endif
