#include "Contact.h"
#include <iostream>

//definitions of all methods of Contact.h

//getters
std::string Contact::getName() const 
{
    return this->name; 
}

std::string Contact::getSurname() const
{
    return this->surname; 
}

std::string Contact::getEmail() const
{
    return this->email;
}

std::string Contact::getNumber() const
{
    return this->phone;
}

//setters
void Contact::setName(std::string newName)  
{
    this->name = newName; 
}

void Contact::setSurname(std::string newSurname)  
{
    this->surname = newSurname; 
}

void Contact::setEmail(std::string newEmail)  
{
    this->email = newEmail; 
}

void Contact::setNumber(std::string newPhone)  
{
    this->phone = newPhone; 
}

void Contact::display() const
{
    std::cout << "Name: " << name << std::endl; 
    std::cout << "Surname: " << surname << std::endl; 
    std::cout << "Email: " << email << std::endl; 
    std::cout << "Phone: " << phone << std::endl; 
}