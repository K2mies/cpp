#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

#define N_MSG 4

class Harl
{
public:
	Harl();
	void complain(std::string level);
private:
	void _debug(void);
	void _info(void);
	void _warning(void);
	void _error(void);
	int _filter(std::string level);
};
#endif
