#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

//Constructor that initializes some variables
PhoneBook::PhoneBook() : _index(-1) {}

PhoneBook::~PhoneBook(void)
{
    // Nothign to clean up since there's no dynamic allocation
}

/**-------------------Public Member Functions---------------------------*/
/**
 * @brief adds a contact to phone book
 */
void    PhoneBook::addContact(void)
{
   _indexHandler();
   _handleInput("First Name: ",     &Contact::setFirstName,     false);
   _handleInput("Last Name: ",      &Contact::setLastName,      false);
   _handleInput("Nick Name: ",      &Contact::setNickName,      false);
   _handleInput("Phone Number: ",   &Contact::setPhoneNumber,   true);
   _handleInput("Darkest Secret: ", &Contact::setDarkestSecret, false);
}
/**
 * @brief searches phonebook for a contact
 */
void    PhoneBook::searchContact(void)
{
    if (_index == -1)
    {
        std::cout << "PhoneBook is empty.\n";
        return;
    }
    _displayAllContact();
    _handleDetailContact();
}


/**------------------Private Member Functions---------------------------*/
/**
* @brief Function incraments index and returns it to 0 if it goes over 7
*This is a very common and efficient way to handle a circular buffer or a 
*fixed-size container, like a phone book that can only hold a certain number
*of entries (in this case, 8). By using the modulo operator, the code ensures 
*that if the index goes past the last element, it automatically loops back to 
*the beginning, preventing it from going out of bounds.
*/
void    PhoneBook::_indexHandler(void)
{
    _index = (_index + 1) % 8;
}

/**
 * @brief truncates the string if over 10 characters
 */
void    PhoneBook::_truncate(std::string str) const
{
    if (str.length() > 10)
    {
        str.resize(9);
        str += ".";
    }
    std::cout << std::setw(10) << str << "|";
}

/**
 * @brief displays all contacts
 * if any of the contacts do not have a value it will exit the loop
 */
void    PhoneBook::_displayAllContact(void) const
{
    std::cout << "     Index|First Name| Last Name|  Nickname\n";
    for (int i = 0; i < 8; i++)
    {
        if(!_contactList[i].hasValue())
        {
            break;
        }
        std::cout << std::setw(10) << i << "|";
        _truncate(_contactList[i].getFirstName());
        _truncate(_contactList[i].getLastName());
        _truncate(_contactList[i].getNickName());
        std::cout << "\n";
    }
}

/**
 * @brief displays single contact
 */
void    PhoneBook::_displaySingleContact(std::string input) const
{
    //checks if the input is a valid digit.
    if (input.length() == 1 && std::isdigit(input[0]))
    {
        int index = input[0] - '0';
        std::cout << "First Name: "     << _contactList[index].getFirstName()       << "\n";
        std::cout << "Last Name: "      << _contactList[index].getLastName()        << "\n";
        std::cout << "Nick Name: "      << _contactList[index].getNickName()        << "\n";
        std::cout << "Phone Number: "   << _contactList[index].getPhoneNumber()     << "\n";
        std::cout << "Darkest Secret: " << _contactList[index].getDarkestSecret()   << "\n";
    }
    else
    {
        std::cout << "Invalid index.\n";
    }
}

/**
 * @gets the indexed contact
 */
void    PhoneBook::_handleDetailContact(void)
{
    std::string input;
    std::cout << "Index: ";
    std::getline(std::cin, input);
    if (!_isValidIndexDetail(input))
    {
        _handleDetailContact();
    }
    else
    {
        _displaySingleContact(input);
    }
}

bool    PhoneBook::_isValidIndexDetail(const std::string &input) const
{
    if (input.length() != 1 || !std::isdigit(input[0]))
    {
        std::cout << "Invalid input.\n";
        return (false);
    }
    int index = input[0] - '0';
    if (index < 0 || index >= 8 || !_contactList[index].hasValue())
    {
        std::cout << "Invalid index.\n";
        return (false);
    }
    return (true);
}

/**
 * @checks wether or not input is valid
 */
bool    PhoneBook::_validInput(const std::string &input, const std::string &allowedChars, size_t minLength) const
{
    if (input.length() < minLength)
    {
        std::cout << "Invalid input.\n";
        return (false);
    }
    for (size_t i = 0; i < input.length(); i++)
    {
        //std::string::npos is returned if .find() does not finda anything
        if (allowedChars.find(input[i]) == std::string::npos)
        {
            std::cout << "Invalid input.\n";
            return (false);
        }
    }
    return (true);
}

/**
 * @checks wether or not field is valid
 */
bool    PhoneBook::_isValidField(const std::string &input, bool justNumber) const
{
    return (_validInput(input, justNumber ? "0123456789" : "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ", 1));
}

void    PhoneBook::_handleInput(const std::string &prompt, void (Contact::*setter)(const std::string &), bool justNumber)
{
    std::string input;

    while (true)
    {
        //Loop untill valid input is provided
        std::cout << prompt;
        std::getline(std::cin, input);

        if (_isValidField(input, justNumber))
        {
            //Validate input, set the value ifvalid, exit loop on valid input.
            (_contactList[_index].*setter)(input);
            break;
        }
        else
        {
            std::cout << "Invalid input. Please try again.\n";
        }
    }
}
