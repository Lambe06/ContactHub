#include "Contact.h"
#include "AddressBook.h"
#include <algorithm> 
#include <iostream> 
#include <fstream> 

void AddressBook::addContact(const Contact& c)
{
    contacts.push_back(c);
}

void AddressBook::removeContact(const std::string& nameToSearch) {
    
    auto it = std::remove_if(contacts.begin(), contacts.end(), [&](const Contact& c) 
    {
        return c.getName() == nameToSearch;
    });

    if (it != contacts.end()) 
    {
        contacts.erase(it, contacts.end());
        std::cout << "Contact removed successfully." << std::endl;
        std::cout << " " << std::endl; 
    } 
    else 
    {
        std::cout << "Contact not found." << std::endl;
        std::cout << " " << std::endl; 
    }
}

bool AddressBook::searchContact(const std::string& query) const 
{
    bool found = false; 

    for (int i = 0; i < contacts.size(); i++) 
    {
        
        if (contacts[i].getName().find(query) != std::string::npos ||  contacts[i].getEmail().find(query) != std::string::npos || contacts[i].getNumber().find(query) != std::string::npos) 
        {

            contacts[i].display();
            std::cout << "-----------------" << std::endl; 
            found = true; 
            
        }
    }

    return found; 
    
}

void AddressBook::displayAll() const
{
    if(contacts.empty())
    {
        std::cout << "The address book is empty." << std::endl; 
        std::cout << " " << std::endl; 
    }

    for(int i = 0; i < contacts.size(); i++)
    {
        contacts[i].display(); 
        std::cout << "-----------------" << std::endl; 
    }
}


void AddressBook::displayWithIndex() const {
    if (contacts.empty()) {
        std::cout << "The address book is empty." << std::endl;
        std::cout << " " << std::endl; 
        return;
    }

    for (int i = 0; i < contacts.size(); i++) {
        std::cout << "[" << i << "] ";
        contacts[i].display(); 
        std::cout << "-----------------" << std::endl; 
    }
}


void AddressBook::removeByIndex(int index) {
    if (index >= 0 && index < contacts.size()) 
    {
        contacts.erase(contacts.begin() + index);
        std::cout << "Contact removed successfully!" << std::endl;
        std::cout << " " << std::endl; 
    } 
    else 
    {
        std::cout << "Invalid selection. No contact removed." << std::endl;
        std::cout << " " << std::endl; 
    }
}

void AddressBook::saveToFile(const std::string& filename) 
{
    std::ofstream outFile(filename);

    if(!outFile)
    {
        std::cerr << "Error opening file for writing!" << std::endl; 
        std::cout << " " << std::endl; 
    }

    for(int i = 0; i < contacts.size(); i++)
    {
        outFile << contacts[i].getName() << "," 
                << contacts[i].getSurname() << ","
                << contacts[i].getEmail() << ","
                << contacts[i].getNumber() << "\n";
    }
    outFile.close();

    std::cout << "Data successfully saved!" << std::endl; 
    std::cout << " " << std::endl; 
}




void AddressBook::loadFromFile(const std::string& filename)
{
    std::ifstream inFile(filename);

    if(!inFile)
    {
        std::cout << "No existing save file found. Starting fresh." << std::endl; 
        std::cout << " " << std::endl; 
    }

    std::string name, surname, email, phone; 
    contacts.clear();

    while(std::getline(inFile, name, ',') && std::getline(inFile, surname, ',') && std::getline(inFile, email, ',') && std::getline(inFile, phone))
    {
        contacts.push_back(Contact(name, surname, email, phone));
    }

    inFile.close();
    std::cout << "Data loaded successfully!" << std::endl; 
    std::cout << " " << std::endl; 

}

bool AddressBook::isEmpty()
{
    if(contacts.size() == 0)
    {
        return true; 
    }
    else 
    {
        return false; 
    }
}

void AddressBook::modifyContact(int index)
{
    
    if (index >= 0 && index < contacts.size())
    {
        int subChoice = 0;
        
        std::cout << "\nWhat would you like to modify?" << std::endl;
        std::cout << "1) Name" << std::endl;
        std::cout << "2) Surname" << std::endl;
        std::cout << "3) Email" << std::endl;
        std::cout << "4) Phone Number" << std::endl;
        std::cout << "Choice: ";

       
        while (!(std::cin >> subChoice) || subChoice < 1 || subChoice > 4)
        {
            std::cout << "Invalid choice! Please enter a number between 1 and 4: ";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }

        std::cin.ignore(10000, '\n'); 

        std::string newValue;
        std::cout << "Enter the new value: ";
        std::getline(std::cin, newValue);

        
        while (newValue.empty())
        {
            std::cout << "Value cannot be empty! Please enter again: ";
            std::getline(std::cin, newValue);
        }

        if (subChoice == 1)
        {
            contacts[index].setName(newValue);
        }
        else if (subChoice == 2)
        {
            contacts[index].setSurname(newValue);
        }
        else if (subChoice == 3)
        {
            contacts[index].setEmail(newValue);
        }
        else if (subChoice == 4)
        {
            contacts[index].setNumber(newValue);
        }

        std::cout << "\nContact updated successfully!" << std::endl;
    }
    else
    {
        std::cout << "Error: Contact index out of range." << std::endl;
    }
}

int AddressBook::getContactsSize() const
{
    return contacts.size();

}
