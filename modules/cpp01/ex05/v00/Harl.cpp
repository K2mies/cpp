#include "Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}

//public member functions
void	Harl::complain(std::string level)
{
	void (Harl::*func[])() = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	i = 0;
	for (std::string lvl : levels)
	{
		if (lvl == level)
		{
			(this->*func[i])();
			return;
		}
		i++;
	}
}

//Private member functions
void Harl::_debug(void)
{
	std::cout << "debug" << std::endl;
}

void Harl::_info(void)
{
	std::cout << "info" << std::endl;
}

void Harl::_warning(void)
{
	std::cout << "warning" << std::endl;
}

void Harl::_error(void)
{
	std::cout << "error" << std::endl;
}
