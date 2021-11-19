#include "contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

void Contact::SetContact(const int id, const std::string contact_data)
{
    this->info_[id] = contact_data;
}

void Contact::PrintList(const int id)
{
    std::cout << "|" << std::setw(9) << id  << "|";
    for (int i = 0; i < 3; i++)
    {
        if (info_[i].length() <= 10)
        {
            std::cout << std::setw(10) << info_[i] << "|";
        }
        else
        {
            std::cout << info_[i].substr(0, 9) << ".|";
        }
    }
    std::cout << std::endl;
}

void Contact::PrintData()
{
    std::string info_name[5] = {"first name", "last name", "nick name",
                                "phone number", "darkest secret"};
    for (int i = 0; i < 5; i++)
    {
        std::cout << info_name[i] << " : ";
        std::cout << info_[i] << std::endl;
    }
}