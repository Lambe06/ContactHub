#include "Contact.h"
#include "AddressBook.h"
#include <string>
#include <fstream>
#include <iostream> 



int main()
{
    AddressBook a; 
    int choice = 0; 

    a.loadFromFile("contacts.csv");

    do
    {
        std::cout << "--- Address Book Menu ---" << std::endl; 
        std::cout << "1) Add a Contact" << std::endl; 
        std::cout << "2) Remove a Contact" << std::endl; 
        std::cout << "3) Search a Contact" << std::endl; 
        std::cout << "4) Display All Contacts" << std::endl;
        std::cout << "5) Modify a Contact" << std::endl; 
        std::cout << "6) Save and exit" << std::endl; 
        std::cout << "\nChoice: "; 

        // Gestione input per la scelta del menu
        while (!(std::cin >> choice))
        {
            std::cout << "Invalid input! Please enter a number: ";
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }

        // Pulizia del buffer per rimuovere il carattere di invio '\n'
        std::cin.ignore(10000, '\n'); 

        if (choice == 1)
        {
            std::string name, surname, email, phone; 
            
            std::cout << "Insert the Name: ";
            std::getline(std::cin, name); 
            
            std::cout << "Insert the Surname: ";
            std::getline(std::cin, surname); 
            
            std::cout << "Insert the email (or skip with S): ";
            std::getline(std::cin, email); 
            
            if (email == "S" || email == "s") 
            {
                email = "No email";
            }

            std::cout << "Insert the phone: ";
            std::getline(std::cin, phone); 

            Contact newContact(name, surname, email, phone);
            a.addContact(newContact);

            std::cout << "\n[!] Contact added successfully!\n" << std::endl; 
        }

        else if (choice == 2)
        {
            std::cout << "\n--- DELETE CONTACT ---" << std::endl; 
            
            if (a.isEmpty()) 
            {
                std::cout << "Address book is empty. Nothing to delete." << std::endl;
                std::cout << std::endl; 
            } 
            else 
            {
                a.displayWithIndex(); 
                int indexToDelete = 0; 
                std::cout << "\nEnter the number (id) to remove: "; 
                
                while (!(std::cin >> indexToDelete))
                {
                    std::cout << "Please enter a valid number: ";
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                }
                
                a.removeByIndex(indexToDelete);
            }
        }

        else if (choice == 3)
        {   
            std::string searchTerm;
            std::cout << "Search (enter any detail): ";
            std::getline(std::cin, searchTerm);

            // Se searchContact restituisce un bool
            if (a.searchContact(searchTerm)) 
            {
                std::cout << "--- Matches Found Above ---" << std::endl; 
                std::cout << std::endl;
            }
            else
            {
                std::cout << "No match found for: " << searchTerm << std::endl; 
                std::cout << std::endl;
            }
        }
        
        else if (choice == 4)
        {
            std::cout << "\n--- ALL CONTACTS ---" << std::endl;
            a.displayAll();
        }
        
        else if (choice == 5)
        {
            a.displayWithIndex();
            int indexSelected = 0;
            std::cout << "Which one do you want to modify? : ";

            
            while (!(std::cin >> indexSelected) || indexSelected < 0 || indexSelected >= a.getContactsSize())
            {
                
                if (std::cin.fail())
                {
                    std::cout << "Invalid input! Please enter a numeric ID: ";
                    std::cin.clear();           
                    std::cin.ignore(10000, '\n'); 
                }
                
                else
                {
                    std::cout << "Error: ID not found. Please choose between 0 and " 
                            << (a.getContactsSize() - 1) << ": ";
                }
            }

            
            a.modifyContact(indexSelected);


        }
        

    } while (choice != 6);
    
    std::cout << "Saving data... Goodbye!" << std::endl;
    a.saveToFile("contacts.csv");
    
    return 0; 
}