#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"

#define MAX_CONTACTS 8

class   PhoneBook
{
private:
    //private member variables
    int _index;
    Contact _contactList[MAX_CONTACTS];
    //private member functions
    void    _indexHandler(void);
    void    _truncate(std::string str) const;

    void    _displayAllContact(void) const;
    void    _displaySingleContact(std::string input) const;

    void    _handleDetailContact(void);
    bool    _isValidIndexDetail(const std::string &input) const;

    bool    _validInput(const std::string &input, const std::string &allowedChars, size_t miniLength) const;
    bool    _isValidField(const std::string &input, bool justNumber) const;
    void    _handleInput(const std::string &prompt, void (Contact::*setter)(const std::string &), bool justNumber);

public:
    //constructor and destructor
    PhoneBook(void);
    ~PhoneBook(void);

    //public member functions
    void    addContact(void);
    void    searchContact(void);
};


#endif
