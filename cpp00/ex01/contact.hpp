#ifndef CONTACT_H
#define CONTACT_H

#include <iomanip>
#include <iostream>
#include <string>

#define DATA_MAX_USER_ID 8

class Contact
{
    public:
        Contact();
        ~Contact();

        void SetContact(const int id, const std::string info);
        void PrintList(const int id);
        void PrintData();

    private:
        std::string info_[5];
};

#endif
