#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
protected:
// ------------------------------------------------------------- member variabls
	std::string idea[100];
public:
// ---------------------------------------------------------------- constructors
	Brain();
	Brain(const Brain &other);
// ------------------------------------------------------------------ destructor
	~Brain();
// --------------------------------------------------- member operator overloads
	Brain &operator=(const Brain &other);
};
#endif
