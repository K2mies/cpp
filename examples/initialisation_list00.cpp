#include <iostream>;
#include "initialisation_list00.hpp"

//Constructor that initialisses variables passed to the constructor.
Sample::Sample(char p1, int p2, float p3)
{
    std::cout << "Constructor called" << std::endl;

    this->a1 = p1;
    std::cout << "this->a1 = " << this->a1 << std::endl;

    this->a2 = p2;
    std::cout << "this->a2 = " << this->a2 << std::endl;

    this->a3 = p3;
    std::cout << "this->a3 = " << this->a3 << std::endl;

    return;
}

//This constructor does the same thing with a diffeent method''
Sample::sample(char p1, int p2, float p3) : a1(p1), a2(p2), a3(p3)
{
    std::cout << "Constructor called" << std::endl;

    std::cout << "this->a1 = " << this->a1 << std::endl;
    std::cout << "this->a2 = " << this->a2 << std::endl;
    std::cout << "this->a3 = " << this->a3 << std::endl;

    return;
}

Sample::~Sample(void)
{
    std::cout << "Constructor called" << std::endl;
    return;
}
