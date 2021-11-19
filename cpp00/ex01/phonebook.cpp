#include "phonebook.hpp"

#include <iomanip>
#include <iostream>
#include <string>
#include <limits>

#define INFO_SIZE 5

Phonebook::Phonebook() { id_ = 0, cnt_ = 0; }

Phonebook::~Phonebook() {}

void Phonebook::AddContact()
{
    std::string info_name[INFO_SIZE] =
    {
        "first name",
        "last name",
        "nick name",
        "phone number",
        "darkest secret"
    };

    std::cout << "Please enter the information:" << std::endl;

    for (int i = 0; i < INFO_SIZE; i++)
    {
        std::cout << std::setfill(' ') << std::setw(15);
        std::cout << info_name[i] << " > ";

        std::string input;
        if (!std::getline(std::cin, input))
        {
            std::cout << "Bye." << std::endl;
            std::exit(1);
        }
        else
        {
            contact_data_[id_].SetContact(i, input);
        }
    }
    std::cout << "id : " << id_ + 1 << " Registered in the Phonebook."
              << std::endl;
    if (cnt_ < MAX_USER_ID)
    {
        cnt_ += 1;
    }
    id_ = (id_ + 1) % MAX_USER_ID;
}

void Phonebook::SearchContact()
{
    if (cnt_ == 0)
    {
        std::cout << "Phonebook is empty." << std::endl;
        return;
    }
    std::cout << "+---------+----------+----------+----------+" << std::endl;
    std::cout << "|    index|first name| last name|  nickname|" << std::endl;
    std::cout << "+---------+----------+----------+----------+" << std::endl;

    for (int i = 0; i < cnt_; i++)
    {
        contact_data_[i].PrintList(i + 1);
    }

    std::cout << "+---------+----------+----------+----------+" << std::endl;

    bool flag = true;
    while (flag)
    {
        std::cout << "Please input the number (" << 1 << "~" << cnt_ << ")"
                  << std::endl;
        std::cout << "> ";
        int index;
        std::cin >> index;
        if (std::cin.eof())
        {
            std::cout << "Bye." << std::endl;
            std::exit(1);
        }

        if (0 < index && index <= cnt_)
        {
            contact_data_[index - 1].PrintData();
            flag = false;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}
