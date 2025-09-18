#include <iostream>
#include <string>

int main()
{
    // intialise each type
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    //lets print the address of each type
    std::cout << "mem adress of str:        "   << &str         << std::endl;
    std::cout << "mem adress of stringPTR:  "   << stringPTR    << std::endl;
    std::cout << "mem adress of stringREF:  "   << &stringREF   << std::endl;
    std::cout << std::endl;
    //now lets print the value of each type
    std::cout << "value of str:         "       << str          << std::endl;
    std::cout << "value of stringPTR:   "       << *stringPTR   << std::endl;
    std::cout << "value of stringREF:   "       << stringREF    << std::endl;
    std::cout << std::endl;
    return (0);
}
