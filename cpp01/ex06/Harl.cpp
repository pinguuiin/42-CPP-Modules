#include "Harl.hpp"

void	Harl::complain(const std::string &level)
{
	std::string filter[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;

	for (; i < 4 && filter[i] != level; ++i) {};
	switch(i) {
		case 0:
			debug();
		case 1:
			info();
		case 2:
			warning();
		case 3:
			error();
			break ;
		default:
			std::cout << "[insignificant problem]" << std::endl;
	}
}

void	Harl::debug(void)
{
	std::cout << "[DEBUG]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger!\n\n";
}

void	Harl::info(void)
{
	std::cout << "[INFO]\nI cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger!\n\n";
}

void	Harl::warning(void)
{
	std::cout << "[WARNING]\nI think I deserve to have some extra bacon for free. You understand?\n\n";
}

void	Harl::error(void)
{
	std::cout << "[ERROR]\nThis is unacceptable! I want to speak to the manager now.\n\n";
}
