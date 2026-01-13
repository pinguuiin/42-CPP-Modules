#pragma once

#include <iostream>
#include <string>

class Brain {

	public:
		Brain();
		Brain(const Brain &other);
		Brain &operator=(const Brain &other);
		~Brain();

	private:
		std::string ideas_[100];
};
