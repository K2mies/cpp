#include "Overload00.hpp"

//Constructoer
Sample::Sample(void)
{
	std::cout << "Constructor called" << std::endl;
	return ;
}

//Destructor
Sample::~Sample(void)
{
	std::cout << "Deconstructor called" << std::endl;
	return ;
}

//Overload functions
void Sample::bar(char const c) const
{
	std::cout << "Member function bar called with char overload : " << c << std::endl;
	return ;
}

void Sample::bar(int const n) const
{
	std::cout << "Member function bar called with int overload : " << n << std::endl;
	return ;
}

void Sample::bar(float const z) const
{
	std::cout << "Member function bar called with float overload : " << z << std::endl;
}

void Sample::bar(Sample const & i) const
{
	(void) i;
	std::cout << "Member function bar called with Sample class overload" << std::endl;
}
