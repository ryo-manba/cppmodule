#include <iostream>
#include <string>
#include "phonebook.hpp"

int main(void)
{
    Phonebook phonebook;

    std::cout << "Usage: ADD / SEARCH / EXIT" << std::endl;
    while (true)
    {
        std::cout << "phonebook> ";
        std::string input;
        if (!std::getline(std::cin, input) || input == "EXIT")
        {
            std::cout << "Bye." << std::endl;
            break ;
        }
        if (input == "ADD")
        {
            phonebook.AddContact();
        }
        else if (input == "SEARCH")
        {
            phonebook.SearchContact();
        }
    }
    return (EXIT_SUCCESS);
}