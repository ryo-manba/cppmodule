#include <iostream>
#include <iomanip>
#include <string>
#include "phonebook.hpp"


int main()
{
    Phonebook phonebook;
    std::string command;

    while (true)
    {

        std::cout << ">";
        std::cin >> command;

        if (command == "ADD")
        {
            phonebook.AddContact();
        }
        if (command == "SEARCH")
        {
            phonebook.SearchContact();
        }
        if (command == "EXIT" || std::cin.eof())
        {
            std::cout << "Bye." << std::endl;
            std::exit(0);
        }
        else
        {
            std::cout << "Invalid Arguments" << std::endl;
            std::cout << "Usage: [ADD / SEARCH / EXIT]" << std::endl;
        }
    }
    return 0;
}