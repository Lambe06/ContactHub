Hi, I'm Riccardo, known as Lambe06 on GitHub, and today i want to present you my new project called "ContactHub"



ContactHub is an application developed in C++ for the management of an address book.



The application is divided in 5 files:



HEADER FILES (.H)



CONTACTS.H -> Header file with declarations of what is a Contact and some methods

ADDRESSBOOK.H -> Header file with declarations of what is an Address Book and its methods



C++ FILES (.CPP)



CONTACTS.CPP -> Definitions of the methods from Contact.h

ADDRESSBOOK.CPP -> Definitions of the methods from AddressBook.h

MAIN.CPP -> The user interface, where you can interact with all the functions of the program



In this program you can:

1. Add a Contact
2. Remove a Contact
3. Search a Contact with filters
4. Display All Contacts
5. Modify a Contact

Maybe in a second version of the code i can add more features…



The memory is managed in a .csv file that will be created in your directory at the beginning of the execution of the application and every time you'll execute the software, it'll take infos from the file.



TO COMPILE ON YOUR PC (please make sure you have installed a compiler for C++):

g++ AddressBook.cpp Contact.cpp -o ContactHub (or other if u prefer...)



TO EXECUTE:

./ContactHub (or the name you have written before...)



This project is Open Source, and you can download the repository without any limit, you can modify the code or also add some new features as you want!



I hope you'll enjoy my work, bye!



MY PROFILE: https://github.com/Lambe06


