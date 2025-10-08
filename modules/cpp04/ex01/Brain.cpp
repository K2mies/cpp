#include "Brain.hpp"

// ----------------------------------------------------------------- constructor
Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
}

// ------------------------------------------------------------ copy constructor
Brain::Brain(const Brain &other)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = other;
}

// --------------------------------------------------- member operator overloads
Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			this->idea[i] = other.idea[i];	
	}
	return (*this);
}

// ------------------------------------------------------------------ destructor
Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}
