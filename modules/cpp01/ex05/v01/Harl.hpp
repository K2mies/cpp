#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

class Harl
{
public:
	void	complain(std::string);
private:
	void	_debug(void);
	void	_info(void);
	void	_warning(void);
	void	_error(void);
	int		_check_level(std::string level);
};

//enums
enum Level
{
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	UNKNOWN
};

#endif
