#include "Contact.hpp"

/**
 * @brief Constructor of a new Contact:: Contact object
 */
Contact::Contact(void)
{
    return;
}

/**
 * @brief Destructor of Contact object
 */
Contact::~Contact(void)
{
    return;
}

/**
 * @brief Getters of Contact class
 */
const std::string Contact::getFirstName(void) const
{
    return (this->_firstName);
}
const std::string Contact::getLirstName(void) const
{
    return (this->_lastName);
}
const std::string Contact::getNickName(void) const
{
    return (this->_nickName);
}
const std::string Contact::getPhoneNumber(void) const
{
    return (this->_phoneNumber);
}
const std::string Contact::getDarkestSecret(void) const
{
    return (this->_darkestSecret);
}

/**
 * @brief Setters of Contact class
 */
void Contact::setFirstName(const std::string &firstName)
{
    this->_firstName = firstName;
}
void Contact::setLastName(const std::string &lastName)
{
    this->_lastName = lastName;
}
void Contact::setNickName(const std::string &nickName)
{
    this->_nickName = nickName;
}
void Constant::setPhoneNumber(const std::string &phoneNumber)
{
    this->_phoneNumber;
}
void Constant::setDarkestSecret(const std::string &darkestSecret)
{
    this->_darkestsecret = darkestSecret;
}
