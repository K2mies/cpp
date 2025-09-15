#include <iostream>
#include "PhoneBook.hpp"

#define CMD_ADD     "1"
#define CMD_SEARCH  "2"
#define CMD_EXIT    "3"

void    menuPrompt(bool &firstTime)
{
    std::cout << "\nPhoneBook Menu:\n"
    if (firstTime)
    {
        std::cout << "welcome to your PhoneBook!\n";
    }
    std::cout << "1. ADD Contact\n";
    std::cout << "2. SEARCH Contacts\n";
    std::cout << "3. EXIT Contact\n";
}

int main()
{
    bool firstTime = true;
    while (true)
    {
        menuPrompt(firstTime);
        firstTime = false;
        std::cout  << "> ";
        std::getline(std::cin, value);

        if (value == CMD_ADD || value == "ADD")
        {
            
        }
    }
    ruturn (0);
}
