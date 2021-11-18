#include "phonebook.hpp"

#include <iomanip>
#include <iostream>
#include <string>

#define DATASIZE 5

Phonebook::Phonebook()
{
    idx = 0;
}

Phonebook::~Phonebook()
{

}

void Phonebook::AddContact()
{
    std::string info_name[DATASIZE] =
    {
        "first name",
        "last name",
        "nick name",
        "phone number",
        "darkest secret"
    };

    std::string info;
    for (int i = 0; i < DATASIZE; i++)
    {
        std::cout << "Please enter the information:" << std::endl;
        std::cout << std::setfill(' ') << std::setw(15);
        std::cout << info_name[i] << " > ";
        std::cin >> info;

        this->contact_[idx % 8].SetContact(i, info);
    }
    std::cout << idx % 8 << " recoded" << std::endl;
}

void Phonebook::SearchContact()
{


}
