#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iomanip>
#include <iostream>
#include <string>

#include "contact.hpp"

#define MAX_USER_ID 8
class Phonebook
{
    public:
        Phonebook();
        ~Phonebook();

        void AddContact();
        void SearchContact();
    private:
        Contact contact_data_[MAX_USER_ID];
        int id_;
        int cnt_;
};

#endif