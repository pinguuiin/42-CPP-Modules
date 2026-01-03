#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {

	public:
		const std::string &getType() const;
		void setType(std::string type);

		Weapon(std::string type);

	private:
		std::string type_;
};

#endif
