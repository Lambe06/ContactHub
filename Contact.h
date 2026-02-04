#ifndef CONTACT_H
#define CONTACT_H
#include <string> 

class Contact
{ //to declare what is a contact, his attributes and some functions
    public: 

    Contact(std::string name, std::string surname, std::string email, std::string phone)
    {
        this->name = name;
        this->surname = surname;
        this->email = email; 
        this->phone = phone; 
    }

    

    //getter methods
    std::string getName() const;
    std::string getSurname() const;
    std::string getEmail() const;
    std::string getNumber() const;
    

    //setters methods
    void setName(std::string newName); 
    void setSurname(std::string newSurname); 
    void setEmail(std::string newEmail); 
    void setNumber(std::string newPhone); 

    void display() const; 



    private: 
    std::string name; 
    std::string surname; 
    std::string email; 
    std::string phone; 


};
#endif