#include "Harl.hpp"

//public member functions
void Harl::complain(std::string level)
{
	void (Harl::*funcPtr)() = nullptr;
	int	level_enum = _check_level(level);

	switch (level_enum)
	{
		case DEBUG:
			funcPtr = &Harl::_debug;
			break;
		case INFO:
			funcPtr = &Harl::_info;
			break;
		case WARNING:
			funcPtr = &Harl::_warning;
			break;
		case ERROR:
			funcPtr = &Harl::_error;
			break;
		default:
			std::cout << "Level not recognized" << std::endl;
			return;
	}
	if (funcPtr)
	{
		(this->*funcPtr)();
	}
}

//private member functions
int Harl::_check_level(std::string level)
{
	if (level == "DEBUG")
		return (DEBUG);
	if (level == "INFO")
		return (INFO);
	if (level == "WARNING")
		return (WARNING);
	if (level == "ERROR")
		return (ERROR);
	return (UNKNOWN);
}

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
