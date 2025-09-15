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
    void    indexHandler(void);
    void    truncate(std::string str) const;

    void    displayAllContact(void) const;
    void    displaySingleContact(std::string input) const;

    void    handleDetailContact(void);
    bool    isValidIndexDetail(const std::string &input) const;

    bool    validInput(const std::string &input, const std::string &allowedChars, size_t miniLength) const;
    bool    isValidField(const std::string &input, bool justNumber) const;
    void    handleInput(const std::string &prompt, void (Contact::*setter)(const std::string &), bool justNumber);

public:
    //constructor and destructor
    PhoneBook(void);
    ~PhoneBook(void);

    //public member functions
    void    addContact(void);
    void    searchContact(void);
};


#endif
