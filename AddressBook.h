#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H
#include "Contact.h"
#include <vector> 
#include <string> 

class AddressBook
{  //declaration of an Addressbook with his own methods 
    public:
    AddressBook() {}
  
    void addContact(const Contact& c);
    //to add contacts to the addressbook
    void removeContact(const std::string& name); 
    //to remove contacts from the addressbook
    bool searchContact(const std::string& query) const;
    //to search contacts per attributes
    void displayAll() const;
    //to see all contacts and their infos
    void displayWithIndex() const; 
    void removeByIndex(int index); 

    bool isEmpty(); 

    void modifyContact(int index);

    int getContactsSize() const ;
    

    void saveToFile(const std::string& filename); //to save info on a .txt file
    void loadFromFile(const std::string& filename); //to load info from a .txt file
    
    private: 
    std::vector<Contact> contacts; 


};
#endif