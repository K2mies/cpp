#include "Harl.hpp"

//Constuctor
Harl::Harl(){}

//Public member functions
void Harl::complain(std::string level)
{
	switch(_filter(level))
	{
		case 0:
			this->_debug();
		case 1:
			this->_info();
		case 2:
			this->_warning();
		case 3:
			this->_error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}

//Private member functions
int Harl::_filter(std::string level)
{
	const std::string levels[N_MSG] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for(int i = 0; i < N_MSG; i++)
	{
		if (levels[i] == level)
			return (i);
	}
	return (-1);
};

//Level Functions
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
