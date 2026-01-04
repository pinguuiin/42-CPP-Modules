#include "Harl.hpp"

void	Harl::complain(const std::string &level)
{
	std::string filter[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*func[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int i = 0;

	for (; i < 4 && filter[i] != level; ++i) {};
	if (i == 4) {
		std::cout << "(silent)" << std::endl;
		return ;
	}
	(this->*func[i])();
}

void	Harl::debug(void)
{
	std::cout << "[DEBUG]I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger!" <<std::endl;
}

void	Harl::info(void)
{
	std::cout << "[INFO]I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[WARNING]I think I deserve to have some extra bacon for free. You understand?" << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ERROR]This is unacceptable! I want to speak to the manager now." << std::endl;
}
