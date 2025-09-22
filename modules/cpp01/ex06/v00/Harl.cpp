#include "Harl.hpp"

//Constructor
Harl::Harl(void){}

//Destructor
Harl::~Harl(void){}

//Public member functions
void Harl::complain(std::string level)
{
	void (Harl::*func[])() = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;
	while (level != levels[i] && i < 4)
		i++;
	switch (i)
	{
		case 0: (this->*func[0])();
		case 1: (this->*func[1])();
		case 2: (this->*func[2])();
		case 3: (this->*func[3])();
			break;
	default: std::cout << "[ Probably complaining about insignificant problems] " << std::endl;
	}
}

//Private member functions
void Harl::_debug(void)
{
	std::cout << "DEBUG" << std::endl;
}

void Harl::_info(void)
{
	std::cout << "INFO" << std::endl;
}

void Harl::_warning(void)
{
	std::cout << "WARNING" << std::endl;
}

void Harl::_error(void)
{
	std::cout << "ERROR" << std::endl;
}
