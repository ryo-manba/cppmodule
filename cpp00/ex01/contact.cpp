#include "contact.hpp"

#include <iomanip>
#include <iostream>

#define PHONE_ID 3

Contact::Contact() {}

Contact::~Contact() {}

bool Contact::IsDigit(const char c)
{
    if ('0' <= c && c <= '9') return (true);
    else return (false);
}

bool Contact::SetContact(const int id, const std::string contact_data)
{
    size_t len = contact_data.length();
    if (len == 0)
    {
        std::cout << std::setw(15) << "ERROR: Please input something" << std::endl;
        return (false);
    }
    if (id == PHONE_ID)
    {
        for (size_t i = 0; i < len; i++)
        {
            if (!IsDigit(contact_data[i]))
            {
                std::cout << std::setw(15) << "ERROR: Please input only numbers" << std::endl;
                return (false);
            }
        }
    }
    this->info_[id] = contact_data;
    return (true);
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
    std::string info_name[5] = {"first name", "last name", "nickname",
                                "phone number", "darkest secret"};
    for (int i = 0; i < 5; i++)
    {
        std::cout << info_name[i] << " : ";
        std::cout << info_[i] << std::endl;
    }
}