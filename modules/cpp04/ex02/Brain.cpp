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

// ----------------------------------------------------------- getters & setters
void	Brain::setIdea(int i, std::string s)
{
	if (i >= 0 && i < 100)
		idea[i] = s;
}

std::string Brain::getIdea(int i)
{
	if (i >= 0 && i < 100)
		return (idea[i]);
	else
	{
		std::cout << "We don't have this many ideas, so here is the first one" << std::endl;
		return (idea[0]);
	}
}
