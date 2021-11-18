#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"

#include <iostream>
#include <iomanip>
#include <string>

#define MAX_SIZE 8
class Phonebook
{
    public:
        Phonebook();
        ~Phonebook();

        void AddContact();
        void SearchContact();
        void ExitPhonebook();

    private:
        Contact contact_[MAX_SIZE];
        int idx;


};

#endif