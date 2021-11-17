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
        if (std::cin.eof()) // Ctrl-D
        {
            std::cout << "Ctrl-D" << std::endl;
            std::exit(1);
        }
        if (command == "ADD")
        {
            phonebook.add_contact();
        }
        if (command == "SEARCH")
        {
            phonebook.search_contact();
        }
        if (command == "EXIT")
        {
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